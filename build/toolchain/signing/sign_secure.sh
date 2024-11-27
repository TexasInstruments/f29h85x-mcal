#!/bin/bash
#
# TPR12 script to generate x509 certificate for secure devices.

#variables
TEMP_X509=./x509-temp.cfg
TSIGN_KEY=keys/rsa4k.pem

VALID_CERT="R5 HSM"
VALID_ENC="ENCRYPT DKEY_ENCRYPT"
VALID_DBG_TYPES="DBG_PERM_DISABLE DBG_SOC_DEFAULT DBG_PUBLIC_ENABLE DBG_FULL_ENABLE"

#Defaults
SHA=sha512
CERT_SIGN=R5
X509_DEFAULT=x509-base.cfg
KD_INFO_VAL=0

if [ "$R5_RBL_SOC" == "tpr12" ]; then
         LOADADDR=0x10200000
elif [ "$R5_RBL_SOC" == "f29h85x" ]; then
         LOADADDR=0x10001000
else
         LOADADDR=0x70002000
fi

# If the variable is not defined, do not enable RSA PSS signature scheme
: "${RSA_PSS_SIG_SCHEME:=0}"


SWRV=1
ENC_IV_VAL=0000
ENC_RS_VAL=0000
ENC_KD_INDEX_VAL=0
ENC_KD_SALT_VAL=0000
DEVICE_UID=0000
DEVICE_DEBUG_TYPE=0000
IMG_KD=0

gen_rsakey() {
	openssl genrsa -out $TSIGN_KEY 4096
	SIGN_KEY=$TSIGN_KEY
}

gen_enckey() {
	echo "Generating Random Encryption Key of 32 bytes:"
	openssl rand -hex 32 > enckey.txt
	ENC_KEY=enckey.txt
}

gen_enciv() {
	echo "Generating Random Encryption IV of 16 bytes:"
	openssl rand -hex 16 > enciv.txt
	ENC_IV=enciv.txt
}

gen_encrs() {
	echo "Generating Random Tail String of 32 bytes:"
	openssl rand -hex 32 > encrs.txt
	ENC_RS=encrs.txt
}

gen_encsalt() {
	echo "Generating SALT for HKDF2 Key generation of 32 bytes:"
	openssl rand -hex 32 > encsalt.txt
	ENC_SALT=encsalt.txt
}

image_encrypt() {
	echo
	echo "Image Encryption is enabled :"
	if [ -z "$ENC_KEY" ]; then
		gen_enckey
		echo "Note: Encryption key is available in enckey.txt:"
	fi

	if [ -z "$ENC_IV" ]; then
		gen_enciv
	fi

	if [ -z "$ENC_RS" ]; then
		gen_encrs
	fi

	ENC_IV_VAL=`cat $ENC_IV`
	ENC_RS_VAL=`cat $ENC_RS`
	echo "ENC_KEY = $ENC_KEY"
	echo "ENC_IV  = $ENC_IV_VAL"
	echo "ENC_RS  = $ENC_RS_VAL"
	cp $BIN  enc_tmp.bin
	truncate -s %16 enc_tmp.bin
	xxd -r -p $ENC_RS enc_rs.bin
	cat enc_tmp.bin  enc_rs.bin > enc_bin_rs.bin
	ENC_BIN=$CERT_SIGN"-ENC-"$BIN
	echo "$ENC_BIN"
	if [ "$IMG_ENC" == "ENCRYPT" ];then
		openssl aes-256-cbc -e -K `cat $ENC_KEY` -iv $ENC_IV_VAL -in enc_bin_rs.bin -out $ENC_BIN -nopad
	else
		echo
		echo "Deriving Encryption Key using HKDF2 scheme :"
		if [ -z "$ENC_SALT" ]; then
			gen_encsalt
		fi
		ENC_KD_INDEX_VAL=1
		ENC_KD_SALT_VAL=`cat $ENC_SALT`
		echo "	ENC_KEY_INDEX  = $ENC_KD_INDEX_VAL"
		echo "	ENC_KEY_SALT  = $ENC_KD_SALT_VAL"
		xxd -r -p $ENC_KEY enc_key.bin
		echo -n '01'| xxd -r -p > 1.bin
		openssl dgst -sha512 -mac hmac -macopt hexkey:`cat $ENC_SALT` enc_key.bin | sed -e 's/.* //g' > encprk.txt
		openssl dgst -sha512 -mac hmac -macopt hexkey:`cat encprk.txt` 1.bin | sed -e 's/.* //g' > encgenkey.txt
		openssl aes-256-cbc -e -K `head -c 64 encgenkey.txt` -iv $ENC_IV_VAL -in enc_bin_rs.bin -out $ENC_BIN -nopad
	fi
	echo "BINARY ENCRYPTION SUCCESS: Generated $ENC_BIN"
	echo
	echo
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
	echo "# Generate x509 certificate for R5 SBL binaries (R5-cert.bin will be created)"
	echo "    $0 -b r5-sbl.bin -c R5 -k rsakey.pem "
	echo "# Encrypt and Generate x509 certificate for R5 SBL binaries (R5-cert.bin R5-ENC-*.bin will be created)"
	echo "    $0 -b r5-sbl.bin -c R5 -k rsakey.pem -y ENCRYPT -e enckey.txt -i enciv.txt -t encrs.txt"
	echo "# Generate derivation key, Encrypt and Generate x509 certificate for R5 SBL binaries (R5-cert.bin R5-ENC-*.bin will be created)"
	echo "    $0 -b r5-sbl.bin -c R5 -k rsakey.pem -y ENCRYPT -e enckey.txt -i enciv.txt -t encrs.txt -x kdsalt.txt -f kdinfo.txt"
}

options_help[b]="bin_file:Bin file that needs to be signed"
options_help[k]="sign_key_file:Siging Key file with key value(PEM). If not provided script generates a random RSA 4K key."
options_help[c]="cert_type:Target core on which the image would be running. Default is R5. Valid option are $VALID_CERT"
options_help[l]="load address of the binary in hex. Default R5:0x10200000"
options_help[s]="SWRV:SWRV value to be included in Certificate supported values (0-47). Default value $SWRV"
options_help[y]="image_encryption:Default is disabled. Valid options are $VALID_ENC"
options_help[e]="enc_key_file:txt file with key inside it. If not provided script generates a random key."
options_help[i]="enc_iv_file:txt file with Encryption Initial Vector(16 bytes) inside it. If not provided script generates a random IV."
options_help[r]="enc_rs_file:txt file with Encryption Tail String(32 bytes) inside it. If not provided script generates a random string."
options_help[d]="debug_extn:Default is disabled. Valid option DEBUG"
options_help[u]="UID_file:txt file with Device Specific Unique ID(32 bytes) included in Debug Extn. Default will be 0"
options_help[j]="debug_type:Debug type to be included in Debug Extn. Valid options are $VALID_DBG_TYPES"
options_help[x]="kd_salt.txt:txt file with key derivation salt String(32 bytes) inside it. Key derivation Object ID is created. A default info is added. To specify info use -f option"
options_help[m]="key lock extension value to be added in certificate"
options_help[o]="crypto lock extension value to be added in certificate"
options_help[f]="kd_info_file:txt file with Info String(32 bytes) inside it"


while getopts "b:c:d:e:f:i:j:k:l:r:s:u:x:y:m:o:h" opt
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
	d)
		IMG_DBG=$OPTARG
		if [ $IMG_DBG != "DEBUG" ]; then
			usage "Invalid debug Option $IMG_DBG"
			exit 1
		fi
	;;
	e)
		ENC_KEY=$OPTARG
	;;
    f)
        KD_INFO=$OPTARG
	;;
    i)
		ENC_IV=$OPTARG
	;;
   	j)
		DEBUG_TYPE=$OPTARG
		dbg_valid=0
		cnt=1
		for tdbg in $VALID_DBG_TYPES
		do
			if [ "$tdbg" == "$DEBUG_TYPE" ]; then
				dbg_valid=$cnt
			fi
			cnt=$(($cnt * 2))
		done
		echo $dbg_valid
		if [ $dbg_valid == 0 ]; then
			usage "Invalid debug_type Option $DEBUG_TYPE"
			exit 1
		else
			DEVICE_DEBUG_TYPE=`expr $dbg_valid / 2`
		fi
	;;
    k)
		SIGN_KEY=$OPTARG
	;;
	l)
		LOADADDR=$OPTARG
	;;
	r)
		ENC_RS=$OPTARG
	;;
    s)
		SWRV=$OPTARG
	;;
	u)
		DEBUG_UID=$OPTARG
	;;
    x)
        IMG_KD=1
        KD_SALT=$OPTARG
	;;
	y)
		IMG_ENC=$OPTARG
		enc_valid=0
		for tenc in $VALID_ENC
		do
			if [ "$tenc" == "$IMG_ENC" ]; then
				enc_valid=1
			fi
		done
		if [ $enc_valid == 0 ]; then
			usage "Invalid Encrypt Option $IMG_ENC"
			exit 1
		fi
	;;
	m)
		KEY_LOCK=$OPTARG
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

#Generate the key derivation.
if [ $IMG_KD -eq 1 ]; then
    KD_SALT_VAL=`cat $KD_SALT`
	echo "	KD_SALT  = $KD_SALT_VAL"
    if [ -z "$KD_INFO" ]; then
		echo "Optional KD info not specified"
        KD_INFO_VAL=0
    else
		echo "Optional KD info specified"
        KD_INFO_VAL=`cat $KD_INFO`
    fi
    echo "	KD_INFO  = $KD_INFO_VAL"
fi

if [ ! -z $IMG_DBG ]; then
	echo
	echo "Debug Extension is Enabled :"
	if [ -z $DEBUG_UID ]; then
		echo "SoC UID not specified for Debug Extension :"
		exit 1
	fi
	DEVICE_UID=`cat $DEBUG_UID`
	echo "	UID = $DEVICE_UID"
	echo "	DBG_TYPE = $DEVICE_DEBUG_TYPE"

fi

#if Image encryption is enabled, encrypt the binary
if [ ! -z $IMG_ENC ]; then
		image_encrypt
		BIN=$ENC_BIN
fi

if [ "$CERT_SIGN" == "R5" ];then
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

#Compute SHA512 of the Binary
SHA_VAL=`openssl dgst -$SHA -hex $BIN | sed -e "s/^.*= //g"`

#Get the Binary Size
BIN_SIZE=`cat $BIN | wc -c | tr -d ' '`
ADDR=`printf "%08x" $LOADADDR`

gen_cert() {
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
		-e "s/TEST_SWRV/$SWRV/" \
		-e "s/KEY_LOCK_VAL/$KEY_LOCK/" \
		-e "s/CRYPTO_LOCK_VAL/$CRYPTO_LOCK/" \
		-e "s/TEST_CERT_TYPE/$CERT_TYPE/" \
		-e "s/TEST_BOOT_CORE_ID/$BOOTCORE_ID/" \
		-e "s/TEST_BOOT_CORE_OPTS/$BOOTCORE_OPTS/" \
		-e "s/TEST_IMAGE_ENC_IV/$ENC_IV_VAL/" \
		-e "s/TEST_IMAGE_ENC_RS/$ENC_RS_VAL/" \
		-e "s/TEST_IMAGE_KEY_DERIVE_INDEX/$ENC_KD_INDEX_VAL/" \
		-e "s/TEST_IMAGE_KEY_DERIVE_SALT/$ENC_KD_SALT_VAL/" \
		-e "s/TEST_IMAGE_KD_SALT/$KD_SALT_VAL/" \
		-e "s/TEST_IMAGE_KD_INFO/$KD_INFO_VAL/" \
		-e "s/TEST_DEVICE_UID/$DEVICE_UID/" \
		-e "s/TEST_DEVICE_DEBUG_TYPE/$DEVICE_DEBUG_TYPE/" \
		-e "s/TEST_BOOT_ADDR/$ADDR/" ${X509_DEFAULT} > $TEMP_X509
	if [ $RSA_PSS_SIG_SCHEME == 1 ];then
		openssl req -new -x509 -key $SIGN_KEY -nodes -outform DER -out $CERT -config $TEMP_X509 -$SHA -days 365 -sigopt rsa_padding_mode:pss -sigopt rsa_pss_saltlen:64 -sigopt rsa_mgf1_md:sha512
	else
		openssl req -new -x509 -key $SIGN_KEY -nodes -outform DER -out $CERT -config $TEMP_X509 -$SHA -days 365
	fi
	echo $TEMP_X509
}

gen_x509template() {
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
  1.3.6.1.4.1.294.1.3=ASN1:SEQUENCE:swrv
__HEADER_EOF

if [ ! -z $IMG_ENC ]; then
	cat << __HEADER_ENC_EOF >> $X509_DEFAULT
  1.3.6.1.4.1.294.1.4=ASN1:SEQUENCE:encryption
__HEADER_ENC_EOF
fi

if [ $IMG_KD -eq 1 ]; then
	cat << __HEADER_KD_EOF >> $X509_DEFAULT
  1.3.6.1.4.1.294.1.5=ASN1:SEQUENCE:key_derivation
__HEADER_KD_EOF
fi

if [ ! -z $IMG_DBG ]; then
	cat << __HEADER_DBG_EOF >> $X509_DEFAULT
  1.3.6.1.4.1.294.1.8=ASN1:SEQUENCE:debug
__HEADER_DBG_EOF
fi

if [ ! -z $KEY_LOCK ]; then
    cat << __KEYLOCK_EXT_EOF >> $X509_DEFAULT
  1.3.6.1.4.1.294.1.11=ASN1:SEQUENCE:keylock
__KEYLOCK_EXT_EOF
fi

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

 [ swrv ]
  swrv         =  INTEGER:TEST_SWRV

__IMAGE_DEFAULT_EOF

if [ ! -z $KEY_LOCK ]; then
    cat << __KEYLOCK_EXT_EOF >> $X509_DEFAULT

 [ keylock ]
  keylock         =  INTEGER:KEY_LOCK_VAL
__KEYLOCK_EXT_EOF
fi

if [ ! -z $CRYPTO_LOCK ]; then
    cat << __CRYPTOLOCK_EXT_EOF >> $X509_DEFAULT

 [ cryptolock ]
  cryptolock         =  INTEGER:CRYPTO_LOCK_VAL
__CRYPTOLOCK_EXT_EOF
fi

if [ ! -z $IMG_ENC ]; then
	cat << __IMAGE_ENC_EOF >> $X509_DEFAULT

 [ encryption ]
  initalVector =  FORMAT:HEX,OCT:TEST_IMAGE_ENC_IV
  randomString =  FORMAT:HEX,OCT:TEST_IMAGE_ENC_RS
  iterationCnt =  INTEGER:TEST_IMAGE_KEY_DERIVE_INDEX
  salt         =  FORMAT:HEX,OCT:TEST_IMAGE_KEY_DERIVE_SALT
__IMAGE_ENC_EOF
fi

if [ $IMG_KD -eq 1 ]; then
	cat << __IMAGE_KD_EOF >> $X509_DEFAULT

 [ key_derivation ]
  salt         =  FORMAT:HEX,OCT:TEST_IMAGE_KD_SALT
  info         =  FORMAT:HEX,OCT:TEST_IMAGE_KD_INFO
__IMAGE_KD_EOF
fi

if [ ! -z $IMG_DBG ]; then
	cat << __IMAGE_DBG_EOF >> $X509_DEFAULT

 [ debug ]
  debugUID     =  FORMAT:HEX,OCT:TEST_DEVICE_UID
  debugType    =  INTEGER:TEST_DEVICE_DEBUG_TYPE
  coreDbgEn    =  INTEGER:0
  coreDbgSecEn =  INTEGER:0
__IMAGE_DBG_EOF
fi
}

gen_cert_noKDInfo() {
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
		-e "s/TEST_SWRV/$SWRV/" \
		-e "s/KEY_LOCK_VAL/$KEY_LOCK/" \
		-e "s/CRYPTO_LOCK_VAL/$CRYPTO_LOCK/" \
		-e "s/TEST_CERT_TYPE/$CERT_TYPE/" \
		-e "s/TEST_BOOT_CORE_ID/$BOOTCORE_ID/" \
		-e "s/TEST_BOOT_CORE_OPTS/$BOOTCORE_OPTS/" \
		-e "s/TEST_IMAGE_ENC_IV/$ENC_IV_VAL/" \
		-e "s/TEST_IMAGE_ENC_RS/$ENC_RS_VAL/" \
		-e "s/TEST_IMAGE_KEY_DERIVE_INDEX/$ENC_KD_INDEX_VAL/" \
		-e "s/TEST_IMAGE_KEY_DERIVE_SALT/$ENC_KD_SALT_VAL/" \
		-e "s/TEST_IMAGE_KD_SALT/$KD_SALT_VAL/" \
		-e "s/TEST_DEVICE_UID/$DEVICE_UID/" \
		-e "s/TEST_DEVICE_DEBUG_TYPE/$DEVICE_DEBUG_TYPE/" \
		-e "s/TEST_BOOT_ADDR/$ADDR/" ${X509_DEFAULT} > $TEMP_X509
	if [ $RSA_PSS_SIG_SCHEME == 1 ];then
		openssl req -new -x509 -key $SIGN_KEY -nodes -outform DER -out $CERT -config $TEMP_X509 -$SHA -days 365 -sigopt rsa_padding_mode:pss -sigopt rsa_pss_saltlen:64 -sigopt rsa_mgf1_md:sha512
	else
		openssl req -new -x509 -key $SIGN_KEY -nodes -outform DER -out $CERT -config $TEMP_X509 -$SHA -days 365
	fi
	readlink -f $TEMP_X509
}

gen_x509template_noKDInfo() {
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
  1.3.6.1.4.1.294.1.3=ASN1:SEQUENCE:swrv
__HEADER_EOF

if [ ! -z $IMG_ENC ]; then
	cat << __HEADER_ENC_EOF >> $X509_DEFAULT
  1.3.6.1.4.1.294.1.4=ASN1:SEQUENCE:encryption
__HEADER_ENC_EOF
fi

if [ $IMG_KD -eq 1 ]; then
	cat << __HEADER_KD_EOF >> $X509_DEFAULT
  1.3.6.1.4.1.294.1.5=ASN1:SEQUENCE:key_derivation
__HEADER_KD_EOF
fi

if [ ! -z $IMG_DBG ]; then
	cat << __HEADER_DBG_EOF >> $X509_DEFAULT
  1.3.6.1.4.1.294.1.8=ASN1:SEQUENCE:debug
__HEADER_DBG_EOF
fi

if [ ! -z $KEY_LOCK ]; then
    cat << __KEYLOCK_EXT_EOF >> $X509_DEFAULT
  1.3.6.1.4.1.294.1.11=ASN1:SEQUENCE:keylock
__KEYLOCK_EXT_EOF
fi

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

 [ swrv ]
  swrv         =  INTEGER:TEST_SWRV

__IMAGE_DEFAULT_EOF


if [ ! -z $KEY_LOCK ]; then
    cat << __KEYLOCK_EXT_EOF >> $X509_DEFAULT

 [ keylock ]
  keylock         =  INTEGER:KEY_LOCK_VAL
__KEYLOCK_EXT_EOF
fi

if [ ! -z $CRYPTO_LOCK ]; then
    cat << __CRYPTOLOCK_EXT_EOF >> $X509_DEFAULT

 [ cryptolock ]
  cryptolock         =  INTEGER:CRYPTO_LOCK_VAL
__CRYPTOLOCK_EXT_EOF
fi


if [ ! -z $IMG_ENC ]; then
	cat << __IMAGE_ENC_EOF >> $X509_DEFAULT

 [ encryption ]
  initalVector =  FORMAT:HEX,OCT:TEST_IMAGE_ENC_IV
  randomString =  FORMAT:HEX,OCT:TEST_IMAGE_ENC_RS
  iterationCnt =  INTEGER:TEST_IMAGE_KEY_DERIVE_INDEX
  salt         =  FORMAT:HEX,OCT:TEST_IMAGE_KEY_DERIVE_SALT
__IMAGE_ENC_EOF
fi

if [ $IMG_KD -eq 1 ]; then
	cat << __IMAGE_KD_EOF >> $X509_DEFAULT

 [ key_derivation ]
  salt         =  FORMAT:HEX,OCT:TEST_IMAGE_KD_SALT
__IMAGE_KD_EOF
fi

if [ ! -z $IMG_DBG ]; then
	cat << __IMAGE_DBG_EOF >> $X509_DEFAULT

 [ debug ]
  debugUID     =  FORMAT:HEX,OCT:TEST_DEVICE_UID
  debugType    =  INTEGER:TEST_DEVICE_DEBUG_TYPE
  coreDbgEn    =  INTEGER:0
  coreDbgSecEn =  INTEGER:0
__IMAGE_DBG_EOF
fi
}

if [ $KD_INFO_VAL == 0 ];then
echo "Generating x509 certificate without KD Info"
gen_x509template_noKDInfo
gen_cert_noKDInfo
else
echo "Generating x509 certificate with KD info"
gen_x509template
gen_cert
fi

echo "CERT GENERATION SUCCESS: Generated $CERT"

#Remove all intermediate files
rm $X509_DEFAULT
#rm enc*.bin enciv.txt encrs.txt encsalt.txt encprk.txt encgenkey.txt 1.bin

#uncomment below to remove local x509 template used to generate certificate
#rm $TEMP_X509

#intentionally not removing *.pem, enckey.txt, *-cert.bin, *ENC*.bin
