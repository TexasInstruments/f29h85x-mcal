#!/bin/bash
#
# TPR12 script to generate x509 certificate for non secure devices.

#variables
TEMP_X509=./x509-temp.cfg
TSIGN_KEY=keys/rsa4k.pem

VALID_CERT="C29 HSM"
#Defaults
SHA=sha512
CERT_SIGN=C29
X509_DEFAULT=x509-base.cfg
COMPUTE_SHA=0

LOADADDR=0x10001000

#TODO
gen_rsakey() {
	openssl genrsa -out $TSIGN_KEY 4096
	SIGN_KEY=$TSIGN_KEY
}

declare -A options_help
usage() {
	if [ -n "$*" ]; then
		echo "ERROR: $*"
	fi
	echo -n "Usage: $0 "
	for option in "${!options_help[@]}"
	do
		arg=`echo ${options_help[$option]}|cut -d ':' -f1`
		if [ -n "$arg" ]; then
			arg=" $arg"
		fi
		echo -n "[-$option$arg] "
	done
	echo
	echo -e "\nWhere:"
	for option in "${!options_help[@]}"
	do
		arg=`echo ${options_help[$option]}|cut -d ':' -f1`
		txt=`echo ${options_help[$option]}|cut -d ':' -f2`
		tb="\t\t\t"
		if [ -n "$arg" ]; then
			arg=" $arg"
			tb="\t"
		fi
		echo -e "   -$option$arg:$tb$txt"
	done
	echo
	echo "Examples of usage:-"
	echo "# Generate x509 certificate for C29 SBL binaries (C29-cert.bin will be created)"
	echo "    $0 -b C29-sbl.bin -c C29 -k rsakey.pem "
	echo "# Encrypt and Generate x509 certificate for C29 SBL binaries (C29-cert.bin C29-ENC-*.bin will be created)"
	echo "    $0 -b C29-sbl.bin -c C29 -k rsakey.pem -y ENCRYPT -e enckey.txt -i enciv.txt -t encrs.txt"
	echo "# Generate derivation key, Encrypt and Generate x509 certificate for C29 SBL binaries (C29-cert.bin C29-ENC-*.bin will be created)"
	echo "    $0 -b C29-sbl.bin -c C29 -k rsakey.pem -y ENCRYPT -e enckey.txt -i enciv.txt -t encrs.txt -x kdsalt.txt -f kdinfo.txt"
}

options_help[b]="bin_file:Bin file that needs to be signed"
options_help[k]="sign_key_file:Siging Key file with key value(PEM). If not provided script generates a random RSA 4K key."
options_help[c]="cert_type:Target core on which the image would be running. Default is C29. Valid option are $VALID_CERT"
options_help[l]="load address of the binary in hex. Default C29:0x10200000"
options_help[o]="crypto lock extension value to be added in certificate"
options_help[i]="Create certificate with image integrity. Default is 0"

while getopts "b:c:f:ik:l:o:h" opt
do
	case $opt in
	b)
		BIN=$OPTARG
	;;
   	c)
		CERT_SIGN=$OPTARG
		cert_valid=0
		for tcert in $VALID_CERT
		do
			if [ "$tcert" == "$CERT_SIGN" ]; then
				cert_valid=1
			fi
		done
		if [ $cert_valid == 0 ]; then
			usage "Invalid Cert type $CERT_SIGN"
			exit 1
		fi
	;;
    i)
        COMPUTE_SHA=1
	;;
    k)
		SIGN_KEY=$OPTARG
	;;
	l)
		LOADADDR=$OPTARG
	;;
	o)
		CRYPTO_LOCK=$OPTARG
	;;
    h)
		usage
		exit 0
	;;
	\?)
		usage "Invalid Option '-$OPTARG'"
		exit 1
	;;
	:)
		usage "Option '-$OPTARG' Needs an argument."
		exit 1
	;;
	esac
done

if [ "$#" -eq 0 ]
then
	usage "Arguments missing"
	exit 1
fi

if [ -z "$BIN" ]; then
	usage "Input bin file missing"
	exit 1
fi

#Generate random key if user doesn't provide a key.
if [ -z "$SIGN_KEY" ]; then
	gen_rsakey
fi

if [ "$CERT_SIGN" == "C29" ];then
	BOOTCORE_ID=16
	CERT_TYPE=1
	BOOTCORE_OPTS=0
else
	LOADADDR=0
	BOOTCORE_ID=0
	CERT_TYPE=2
	BOOTCORE_OPTS=0
fi

#Create CERT name
CERT=$CERT_SIGN"-cert.bin"

if [ $COMPUTE_SHA == 1 ];then
echo "Computing SHA Value"
#Compute SHA512 of the Binary
SHA_VAL=`openssl dgst -$SHA -hex $BIN | sed -e "s/^.*= //g"`
else
echo "Skipping SHA Computation"
SHA_VAL=0
fi

#Get the Binary Size
BIN_SIZE=`cat $BIN | wc -c | tr -d ' '`
ADDR=`printf "%08x" $LOADADDR`

gen_int_cert() {
	echo "$CERT_SIGN Certificate being generated :"
	echo "	X509_CFG = $TEMP_X509"
	echo "	KEY = $SIGN_KEY"
	echo "	BIN = $BIN"
	echo "	CERT TYPE = $CERT_SIGN"
	echo "	CORE ID = $CERT_TYPE "
	echo "	LOADADDR = 0x$ADDR"
	echo "	IMAGE_SIZE = $BIN_SIZE"
	sed -e "s/TEST_IMAGE_LENGTH/$BIN_SIZE/"	\
		-e "s/TEST_IMAGE_SHA512/$SHA_VAL/" \
		-e "s/CRYPTO_LOCK_VAL/$CRYPTO_LOCK/" \
		-e "s/TEST_CERT_TYPE/$CERT_TYPE/" \
		-e "s/TEST_BOOT_CORE_ID/$BOOTCORE_ID/" \
		-e "s/TEST_BOOT_CORE_OPTS/$BOOTCORE_OPTS/" \
		-e "s/TEST_BOOT_ADDR/$ADDR/" ${X509_DEFAULT} > $TEMP_X509
	openssl req -new -x509 -key $SIGN_KEY -nodes -outform DER -out $CERT -config $TEMP_X509 -$SHA -days 365
}

gen_int_x509template() {
cat << __HEADER_EOF > $X509_DEFAULT
 [ req ]
 distinguished_name     = req_distinguished_name
 x509_extensions        = v3_ca
 prompt                 = no

 dirstring_type = nobmp

 [ req_distinguished_name ]
 C                      = US
 ST                     = MD
 L                      = Germantown
 O                      = Texas Instruments., Inc.
 OU                     = RADAR PROCESSOR
 CN                     = Anonymous, Anonymous
 emailAddress           = anonymous@ti.com

 [ v3_ca ]
  basicConstraints = CA:true
  1.3.6.1.4.1.294.1.1=ASN1:SEQUENCE:boot_seq
  1.3.6.1.4.1.294.1.2=ASN1:SEQUENCE:image_integrity
__HEADER_EOF

if [ ! -z $CRYPTO_LOCK ]; then
    cat << __CRYPTOLOCK_EXT_EOF >> $X509_DEFAULT
  1.3.6.1.4.1.294.1.12=ASN1:SEQUENCE:cryptolock
__CRYPTOLOCK_EXT_EOF
fi

cat << __IMAGE_DEFAULT_EOF >> $X509_DEFAULT

 [ boot_seq ]
  certType     =  INTEGER:TEST_CERT_TYPE
  bootCore     =  INTEGER:TEST_BOOT_CORE_ID
  bootCoreOpts =  INTEGER:TEST_BOOT_CORE_OPTS
  destAddr     =  FORMAT:HEX,OCT:TEST_BOOT_ADDR
  imageSize    =  INTEGER:TEST_IMAGE_LENGTH

 [ image_integrity ]
  shaType      =  OID:2.16.840.1.101.3.4.2.3
  shaValue     =  FORMAT:HEX,OCT:TEST_IMAGE_SHA512
__IMAGE_DEFAULT_EOF

if [ ! -z $CRYPTO_LOCK ]; then
    cat << __CRYPTOLOCK_EXT_EOF >> $X509_DEFAULT

 [ cryptolock ]
  cryptolock         =  INTEGER:CRYPTO_LOCK_VAL
__CRYPTOLOCK_EXT_EOF
fi

}

gen_noint_cert() {
	echo "$CERT_SIGN Certificate being generated :"
	echo "	X509_CFG = $TEMP_X509"
	echo "	KEY = $SIGN_KEY"
	echo "	BIN = $BIN"
	echo "	CERT TYPE = $CERT_SIGN"
	echo "	CORE ID = $CERT_TYPE "
	echo "	LOADADDR = 0x$ADDR"
	echo "	IMAGE_SIZE = $BIN_SIZE"
	sed -e "s/TEST_IMAGE_LENGTH/$BIN_SIZE/"	\
		-e "s/CRYPTO_LOCK_VAL/$CRYPTO_LOCK/" \
		-e "s/TEST_CERT_TYPE/$CERT_TYPE/" \
		-e "s/TEST_BOOT_CORE_ID/$BOOTCORE_ID/" \
		-e "s/TEST_BOOT_CORE_OPTS/$BOOTCORE_OPTS/" \
		-e "s/TEST_BOOT_ADDR/$ADDR/" ${X509_DEFAULT} > $TEMP_X509
	openssl req -new -x509 -key $SIGN_KEY -nodes -outform DER -out $CERT -config $TEMP_X509 -$SHA -days 365
}

gen_noint_x509template() {
cat << __HEADER_EOF > $X509_DEFAULT
 [ req ]
 distinguished_name     = req_distinguished_name
 x509_extensions        = v3_ca
 prompt                 = no

 dirstring_type = nobmp

 [ req_distinguished_name ]
 C                      = US
 ST                     = MD
 L                      = Germantown
 O                      = Texas Instruments., Inc.
 OU                     = RADAR PROCESSOR
 CN                     = Anonymous, Anonymous
 emailAddress           = anonymous@ti.com

 [ v3_ca ]
  basicConstraints = CA:true
  1.3.6.1.4.1.294.1.1=ASN1:SEQUENCE:boot_seq
__HEADER_EOF

if [ ! -z $CRYPTO_LOCK ]; then
    cat << __CRYPTOLOCK_EXT_EOF >> $X509_DEFAULT
  1.3.6.1.4.1.294.1.12=ASN1:SEQUENCE:cryptolock
__CRYPTOLOCK_EXT_EOF
fi

cat << __IMAGE_DEFAULT_EOF >> $X509_DEFAULT

 [ boot_seq ]
  certType     =  INTEGER:TEST_CERT_TYPE
  bootCore     =  INTEGER:TEST_BOOT_CORE_ID
  bootCoreOpts =  INTEGER:TEST_BOOT_CORE_OPTS
  destAddr     =  FORMAT:HEX,OCT:TEST_BOOT_ADDR
  imageSize    =  INTEGER:TEST_IMAGE_LENGTH
__IMAGE_DEFAULT_EOF

if [ ! -z $CRYPTO_LOCK ]; then
    cat << __CRYPTOLOCK_EXT_EOF >> $X509_DEFAULT

 [ cryptolock ]
  cryptolock         =  INTEGER:CRYPTO_LOCK_VAL
__CRYPTOLOCK_EXT_EOF
fi

}


if [ $COMPUTE_SHA == 1 ];then
echo "Generating x509 certificate with integrity"
gen_int_x509template
gen_int_cert
else
echo "Generating x509 certificate without integrity"
gen_noint_x509template
gen_noint_cert
fi

echo "CERT GENERATION SUCCESS: Generated $CERT"

#Remove all intermediate files
rm $X509_DEFAULT
#rm enc*.bin enciv.txt encrs.txt encsalt.txt encprk.txt encgenkey.txt 1.bin

#uncomment below to remove local x509 template used to generate certificate
#rm $TEMP_X509

#intentionally not removing *.pem, enckey.txt, *-cert.bin, *ENC*.bin
