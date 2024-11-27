# TRP12 script to generate X509 certificate for non secure devices
import subprocess
import argparse
import os
import textwrap
import path

# Template certificate and default RSA key
TEMP_X509 = "x509-temp.cfg"
TSIGN_KEY = "keys/rsa4k.pem"
VALID_CERT = ["C29", "HSM"]
SIGN_KEY = None
BIN = None

# Defaults
SHA = "sha512"
CERT_SIGN = "C29"
X509_DEFAULT = "x509-base.cfg"
COMPUTE_SHA = 0

# X509 Template Variable
BOOTCORE_ID = None
CERT_TYPE = None
BOOTCORE_OPTS = None
LOADADDR = 0x10001000
CERT = None
SHA_VAL = None
BIN_SIZE = None
ADDR = None
CRYPTO_LOCK = None

DIR_NAME = None


def gen_rsakey() -> str:
    """
    Generates a 4096 bit RSA private key using openSSL. The key is saved
    in rsa4k.pem
    """
    global TSIGN_KEY
    subprocess.check_output(
        f"openssl genrsa -out {TSIGN_KEY} 4096", shell=True
    ).decode()
    return TSIGN_KEY


def usage(err=None) -> None:
    if not (err is None):
        print(f"ERROR: {err}")
        return
    else:
        pass


def initParser():
    parser = argparse.ArgumentParser(
        description="Generates X509 certificate for an application binary to boot"
    )
    parser.add_argument(
        "--b", type=str, help="bin_file:Bin file that needs to be signed"
    )
    parser.add_argument(
        "--c",
        type=str,
        help="cert_type:Target core on which the image would be running",
    )
    parser.add_argument(
        "--i", type=str, help="Create certificate with image integrit. Default is 0"
    )
    parser.add_argument(
        "--k",
        type=str,
        help="sign_key_file:Siging Key file with key value(PEM). If not provided script generates a random RSA 4K key.",
    )
    parser.add_argument(
        "--l",
        type=str,
        help="load address of the binary in hex. Default C29:0x10200000",
    )
    parser.add_argument(
        "--o", type=str, help="crypto lock extension value to be added in certificate"
    )

    return parser


def parseArgs(args) -> int:
    """
    Generates the x509 certificate config.
    Return value:
        0: SUCCESS
        1: FALURE
    """
    global BIN, VALID_CERT, CERT_SIGN, COMPUTE_SHA, SIGN_KEY, LOADADDR, CRYPTO_LOCK, DIR_NAME, TEMP_X509
    if (args.b is None) or (not os.path.exists(args.b)):
        usage(f"Input binary file is missing")
        return 1

    BIN = args.b

    if (args.c is None) or (not (args.c in VALID_CERT)):
        usage(f"Certificate type {args.c} is not valid")
        return 1

    DIR_NAME = os.path.dirname(BIN)
    TEMP_X509 = os.path.join(DIR_NAME, TEMP_X509)
    CERT_SIGN = args.c

    if args.i == "y":
        COMPUTE_SHA = 1

    if args.k is None:
        SIGN_KEY = gen_rsakey()
    else:
        SIGN_KEY = args.k

    if not (args.l is None):
        LOADADDR = int(args.l, 16)

    if not (args.o is None):
        CRYPTO_LOCK = args.o

    return 0


def setupArgs():
    """
    Set the X509 certificate template varguments based on arguments from
    parseArgs()
    """
    global LOADADDR, CERT_SIGN, BOOTCORE_ID, CERT_TYPE, BOOTCORE_OPTS, CERT, SHA_VAL, BIN_SIZE, ADDR, COMPUTE_SHA, SHA, BIN

    if CERT_SIGN == "C29":
        BOOTCORE_ID = 16
        CERT_TYPE = 1
        BOOTCORE_OPTS = 0
    else:
        LOADADDR = 0
        BOOTCORE_ID = 0
        CERT_TYPE = 2
        BOOTCORE_OPTS = 0

    # Create Certificate Name
    CERT = f"{CERT_SIGN}-cert.bin"
    CERT = os.path.join(DIR_NAME, CERT)

    # Compute SHA512 of the binary file
    if COMPUTE_SHA:
        print(f"Computing {SHA} value for {BIN}")
        output = subprocess.check_output(
            f"openssl dgst -{SHA} -hex {BIN}", shell=True
        ).decode()
        pos = output.find("= ")
        if pos != -1:
            SHA_VAL = output[pos + 2 :].strip()
    else:
        print(f"Skipping {SHA} computation for {BIN}")
        SHA_VAL = 0

    # Get the binary size
    BIN_SIZE = os.path.getsize(f"{BIN}")
    ADDR = format(LOADADDR, "08x")


g_x509_int_template_header = """
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
"""
g_x509_int_template_cryptlock_ext = """
1.3.6.1.4.1.294.1.12=ASN1:SEQUENCE:cryptolock
"""
g_x509_int_template_image_default = """
[ boot_seq ]
certType     =  INTEGER:{TEST_CERT_TYPE}
bootCore     =  INTEGER:{TEST_BOOT_CORE_ID}
bootCoreOpts =  INTEGER:{TEST_BOOT_CORE_OPTS}
destAddr     =  FORMAT:HEX,OCT:{TEST_BOOT_ADDR}
imageSize    =  INTEGER:{TEST_IMAGE_LENGTH}

[ image_integrity ]
shaType = OID:2.16.840.1.101.3.4.2.3
shaValue = FORMAT:HEX,OCT:{TEST_IMAGE_SHA512}
"""

g_x509_int_template_cryptlock = """
[ cryptolock ]
cryptolock         =  INTEGER:{TEST_CRYPTO_LOCK_VAL}
"""


def gen_int_cert():
    print(f"\n{CERT_SIGN} Certificate being generated with Integrity: ")
    print(f"X509_CFG = {TEMP_X509}")
    print(f"KEY = {SIGN_KEY}")
    print(f"CERT TYPE = {CERT_SIGN}")
    print(f"BIN = {BIN}")
    print(f"CORE ID = {CERT_TYPE}")
    print(f"LOADADDR = 0x{ADDR}")
    print(f"IMAGE_SIZE = {BIN_SIZE}\n")

    ret_cert = g_x509_int_template_header
    if not (CRYPTO_LOCK is None):
        ret_cert += g_x509_int_template_cryptlock_ext
    ret_cert += g_x509_int_template_image_default.format(
        TEST_IMAGE_LENGTH=BIN_SIZE,
        TEST_CERT_TYPE=CERT_TYPE,
        TEST_BOOT_CORE_ID=BOOTCORE_ID,
        TEST_BOOT_CORE_OPTS=BOOTCORE_OPTS,
        TEST_BOOT_ADDR=ADDR,
        TEST_IMAGE_SHA512=SHA_VAL,
    )
    if not (CRYPTO_LOCK is None):
        ret_cert += g_x509_int_template_cryptlock.format(
            TEST_CRYPTO_LOCK_VAL=CRYPTO_LOCK
        )

    # write the template certificate to a file
    with open(TEMP_X509, "w+") as fd:
        fd.write(textwrap.dedent(ret_cert))

    # Generate the X509 certificate via OpenSSL and template
    subprocess.check_output(
        f"openssl req -new -x509 -key {SIGN_KEY} -nodes -outform DER -out {CERT} -config {TEMP_X509} -{SHA} -days 365",
        shell=True,
    ).decode()

    return


g_x509_noint_template_header = """
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
"""

g_x509_noint_template_cryptlock_ext = """
1.3.6.1.4.1.294.1.12=ASN1:SEQUENCE:cryptolock
"""

g_x509_noint_template_image_default = """
[ boot_seq ]
certType     =  INTEGER:{TEST_CERT_TYPE}
bootCore     =  INTEGER:{TEST_BOOT_CORE_ID}
bootCoreOpts =  INTEGER:{TEST_BOOT_CORE_OPTS}
destAddr     =  FORMAT:HEX,OCT:{TEST_BOOT_ADDR}
imageSize    =  INTEGER:{TEST_IMAGE_LENGTH}
"""

g_x509_noint_template_cryptlock = """
[ cryptolock ]
cryptolock         =  INTEGER:{TEST_CRYPTO_LOCK_VAL}
"""


def gen_noint_cert():
    print(f"\n{CERT_SIGN} Certificate being generated without Integrity: ")
    print(f"X509_CFG = {TEMP_X509}")
    print(f"KEY = {SIGN_KEY}")
    print(f"CERT TYPE = {CERT_SIGN}")
    print(f"BIN = {BIN}")
    print(f"CORE ID = {CERT_TYPE}")
    print(f"LOADADDR = 0x{ADDR}")
    print(f"IMAGE_SIZE = {BIN_SIZE}\n")

    ret_cert = g_x509_noint_template_header
    if not (CRYPTO_LOCK is None):
        ret_cert += g_x509_noint_template_cryptlock_ext
    ret_cert += g_x509_noint_template_image_default.format(
        TEST_IMAGE_LENGTH=BIN_SIZE,
        TEST_CERT_TYPE=CERT_TYPE,
        TEST_BOOT_CORE_ID=BOOTCORE_ID,
        TEST_BOOT_CORE_OPTS=BOOTCORE_OPTS,
        TEST_BOOT_ADDR=ADDR,
    )
    if not (CRYPTO_LOCK is None):
        ret_cert += g_x509_noint_template_cryptlock.format(
            TEST_CRYPTO_LOCK_VAL=CRYPTO_LOCK
        )

    # write the template certificate to file
    with open(TEMP_X509, "w+") as fd:
        fd.write(textwrap.dedent(ret_cert))

    # Generate the X509 certificate via OpenSSL and template
    subprocess.check_output(
        f"openssl req -new -x509 -key {SIGN_KEY} -nodes -outform DER -out {CERT} -config {TEMP_X509} -{SHA} -days 365",
        shell=True,
    ).decode()

    return


if __name__ == "__main__":
    parser = initParser()
    args = parser.parse_args()
    err = parseArgs(args)
    if not err:
        setupArgs()
        if COMPUTE_SHA:
            print("\n[[Generating X509 certificate]]\n")
            gen_int_cert()
        else:
            print("\n[[Generating X509 certificate]]\n")
            gen_noint_cert()

        print(f"\n[[CERT GENERATION SUCCESS: Generated {CERT}]]\n")

    else:
        print("\n[[Error generating X509 certificate for given binary file]]\n")
