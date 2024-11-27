# TRP12 script to generate X509 certificate for non secure devices
import subprocess
import argparse
import os
import textwrap
import shutil
import binascii
import re
import path

# Template certificate and default RSA key
TEMP_X509 = "x509-temp.cfg"
TSIGN_KEY = "rsa4k.pem"
VALID_CERT = ["C29", "HSM"]
VALID_ENC = ["ENCRYPT", "DKEY_ENCRYPT"]
VALID_DBG_TYPES = [
    "DBG_PERM_DISABLE",
    "DBG_SOC_DEFAULT",
    "DBG_PUBLIC_ENABLE",
    "DBG_FULL_ENABLE",
]
SIGN_KEY = None
ENC_KEY = None
ENC_IV = None
ENC_RS = None
ENC_SALT = None
BIN = None

# Defaults
SHA = "sha512"
CERT_SIGN = "C29"
X509_DEFAULT = "x509-base.cfg"
KD_INFO_VAL = 0
COMPUTE_SHA = 0

LOADADDR = "0x10001000"
SWRV = 1
ENC_IV_VAL = 0
ENC_RS_VAL = 0
ENC_KEY_VAL = 0
ENC_KD_INDEX_VAL = 0
ENC_KD_SALT_VAL = 0
DEVICE_UID = 0
DEVICE_DEBUG_TYPE = 0
IMG_KD = 0

# Passed Arguments
IMG_ENC = None
IMG_DBG = None
KD_INFO = None
DEBUG_UID = None
DEBUG_TYPE = None
KD_SALT = None
KEY_LOCK = None
CRYPTO_LOCK = None
KD_SALT_VAL = None
ENC_BIN = None
CERT = None
BIN_SIZE = 0
ADDR = 0
CERT_TYPE = 0
BOOTCORE_ID = 0
BOOTCORE_OPTS = 0
DIR_NAME = None


def gen_rsakey():
    global SIGN_KEY, TSIGN_KEY
    subprocess.check_output(
        f"openssl genrsa -out {TSIGN_KEY} 4096", shell=True
    ).decode()
    SIGN_KEY = TSIGN_KEY


def gen_enckey():
    global ENC_KEY
    print(f"Generating Random Encryption Key of 32 bytes:")
    subprocess.check_output(
        f"openssl rand -hex 32 > keys/enckey.txt", shell=True
    ).decode()
    ENC_KEY = "keys/enckey.txt"


def gen_enciv():
    global ENC_IV
    print(f"Generating Random Ecryption IV of 16 bytes:")
    subprocess.check_output(
        f"openssl rand -hex 16 > keys/enciv.txt", shell=True
    ).decode()
    ENC_IV = "keys/enciv.txt"


def gen_encrs():
    global ENC_RS
    print(f"Generating Random Tail String of 32 bytes:")
    subprocess.check_output(
        f"openssl rand -hex 32 > keys/encrs.txt", shell=True
    ).decode()
    ENC_RS = "keys/encrs.txt"


def gen_encsalt():
    global ENC_SALT
    print(f"Generating SALT for HKDF2 Key generation of 32 bytes:")
    subprocess.check_output(
        f"openssl rand -hex 32 > keys/encsalt.txt", shell=True
    ).decode()
    ENC_SALT = "keys/encrs.txt"


def get_val_from_file(file_path):
    with open(file_path, "r") as file:
        val = file.read().strip()

    return val


def get_binary_from_hex(src_file, dest_file):
    hex_data = None
    with open(src_file, "r") as fd:
        hex_data = fd.read().strip()

    binary_data = binascii.unhexlify(hex_data)

    with open(dest_file, "wb") as fd:
        fd.write(binary_data)


def image_encrypt():
    global ENC_KEY, ENC_IV, ENC_RS, ENC_SALT, ENC_BIN
    global ENC_IV_VAL, ENC_RS_VAL, ENC_KEY_VAL, ENC_KD_INDEX_VAL, ENC_KD_SALT_VAL
    global BIN, IMG_ENC, CERT_SIGN, OUT_DIR
    print(f"Image Encryption is enabled")
    if ENC_KEY is None:
        gen_enckey()
        print(f"Note: Encryption Key is available in {ENC_KEY}")

    if ENC_IV is None:
        gen_enciv()

    if ENC_RS is None:
        gen_encrs()

    ENC_IV_VAL = get_val_from_file(ENC_IV)
    ENC_RS_VAL = get_val_from_file(ENC_RS)
    ENC_KEY_VAL = get_val_from_file(ENC_KEY)
    print(f"ENC_KEY = {ENC_KEY}")
    print(f"ENC_IV = {ENC_IV_VAL}")
    print(f"ENC_RS = {ENC_RS_VAL}")

    shutil.copy(BIN, "enc_tmp.bin")

    # truncate the enc_tmp.bin to multiple of 16
    with open("enc_tmp.bin", "ab+") as fd:
        size = fd.tell()
        fd.truncate(size - size % 16)

    get_binary_from_hex(ENC_RS, "enc_rs.bin")

    # concat enc_tmp.bin and erc_rs.bin to enc_bin_rs.bin
    with open("enc_tmp.bin", "rb") as f1, open("enc_rs.bin", "rb") as f2, open(
        "enc_bin_rs.bin", "wb"
    ) as of:
        shutil.copyfileobj(f1, of)
        shutil.copyfileobj(f2, of)

    ENC_BIN = f"{CERT_SIGN}-ENC-{BIN}"
    print(f"ENC_BIN = {ENC_BIN}")

    if IMG_ENC == "ENCRYPT":
        # Encrypt using AES-256
        subprocess.check_output(
            f"openssl aes-256-cbc -e -K {ENC_KEY_VAL} -iv {ENC_IV_VAL} -in enc_bin_rs.bin -out {ENC_BIN} -nopad",
            shell=True,
        ).decode()
    else:
        print(f"Deriving Encryption key using HKDF2 scheme")
        if ENC_SALT is None:
            gen_encsalt()

        ENC_KD_INDEX_VAL = 1
        ENC_KD_SALT_VAL = get_val_from_file(ENC_SALT)
        print(f"ENC_KEY_INDEX = {ENC_KD_INDEX_VAL}")
        print(f"ENC_KEY_SALT = {ENC_KD_SALT_VAL}")

        get_binary_from_hex(ENC_KEY, "enc_key.bin")

        # write 01 in binary data to file 1.bin
        binary_data = binascii.unhexlify("01")
        with open("1.bin", "wb") as fd:
            fd.write(binary_data)

        out_hmac = subprocess.check_output(
            f"openssl dgst -sha512 -mac hmac -macopt hexkey:{ENC_KD_SALT_VAL} enc_key.bin"
        ).decode()
        encprk = re.sub(r".* ", "", out_hmac)
        with open("encprk.txt", "w") as fd:
            fd.write(encprk)

        outgenkey = subprocess.check_output(
            f"openssl dgst -sha512 -mac hmac -macopt hexkey:{encprk} 1.bin"
        ).decode()
        encgenkey = re.sub(r".* ", "", outgenkey)
        with open("encprk.txt", "w") as fd:
            fd.write(encgenkey)

        # Read the first 64 bytes of encgenkey.txt
        encgenkey_first_64_byes = None
        with open("encgenkey.txt", "rb") as fd:
            encgenkey_first_64_byes = fd.read(64)

        # Ecrypt using AES-256
        subprocess.check_output(
            f"openssl aes-256-cbc -e -K {encgenkey_first_64_byes} -iv {ENC_IV_VAL} -in enc_bin_rs.bin -out {ENC_BIN} -nopad",
            shell=True,
        ).decode()

        print(f"Binary Encryption Success: Generated {ENC_BIN}")


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
        "--b", type=str, help=f"bin_file:Bin file that needs to be signed"
    )
    parser.add_argument(
        "--k",
        type=str,
        help=f"sign_key_file:Siging Key file with key value(PEM). If not provided script generates a random RSA 4K key.",
    )
    parser.add_argument(
        "--c",
        type=str,
        help=f"cert_type:Target core on which the image would be running. Default is C29. Valid options are {VALID_CERT}",
    )
    parser.add_argument(
        "--l",
        type=str,
        help=f"load address of the binary in hex. Default C29:0x10200000",
    )
    parser.add_argument(
        "--s",
        type=str,
        help=f"SWRV:SWRV value to be included in Certificate supported values (0-47). Default value {SWRV}",
    )
    parser.add_argument(
        "--y",
        type=str,
        help=f"image_encryption:Default is disabled. Valid options are {VALID_ENC}",
    )
    parser.add_argument(
        "--e",
        type=str,
        help=f"enc_key_file:txt file with key inside it. If not provided script generates a random key.",
    )
    parser.add_argument(
        "--i",
        type=str,
        help=f"enc_iv_file:txt file with Encryption Initial Vector(16 bytes) inside it. If not provided script generates a random IV.",
    )
    parser.add_argument(
        "--r",
        type=str,
        help=f"enc_rs_file:txt file with Encryption Tail String(32 bytes) inside it. If not provided script generates a random string.",
    )
    parser.add_argument(
        "--d", type=str, help=f"debug_extn:Default is disabled. Valid option DEBUG"
    )
    parser.add_argument(
        "--u",
        type=str,
        help=f"UID_file:txt file with Device Specific Unique ID(32 bytes) included in Debug Extn. Default will be 0",
    )
    parser.add_argument(
        "--j",
        type=str,
        help=f"debug_type:Debug type to be included in Debug Extn. Valid options are {VALID_DBG_TYPES}",
    )
    parser.add_argument(
        "--x",
        type=str,
        help=f"kd_salt.txt:txt file with key derivation salt String(32 bytes) inside it. Key derivation Object ID is created. A default info is added. To specify info use -f option",
    )
    parser.add_argument(
        "--m", type=str, help=f"key lock extension value to be added in certificate"
    )
    parser.add_argument(
        "--o", type=str, help=f"crypto lock extension value to be added in certificate"
    )
    parser.add_argument(
        "--f",
        type=str,
        help=f"kd_info_file:txt file with Info String(32 bytes) inside it",
    )
    parser.add_argument(
        "--t", type=str, help=f"target directory to generate signed binaries"
    )

    return parser


def parseArgs(args) -> int:
    """
    Generates the x509 certificate config.
    Return value:
        0: SUCCESS
        1: FALURE
    """
    global BIN, CERT_SIGN, VALID_CERT, IMG_DBG, ENC_KEY
    global KD_INFO, ENC_IV, DEBUG_TYPE, VALID_DBG_TYPES, DEVICE_DEBUG_TYPE
    global SIGN_KEY, LOADADDR, ENC_RS, SWRV, DEBUG_UID, IMG_ENC
    global KEY_LOCK, CRYPTO_LOCK, IMG_KD, KD_SALT
    # --b
    BIN = args.b

    # --c
    CERT_SIGN = args.c
    if not (CERT_SIGN in VALID_CERT):
        usage(f"Invalid Certificate type")
        return 1

    # --d
    IMG_DBG = args.d
    if IMG_DBG != None and IMG_DBG != "DEBUG":
        usage(f"Invalid debug option {IMG_DBG}")
        return 1

    # --e
    ENC_KEY = args.e

    # --f
    KD_INFO = args.f

    # --i
    ENC_IV = args.i

    # --j
    DEBUG_TYPE = args.j
    dbg_valid, cnt = 0, 1
    for tdbg in VALID_DBG_TYPES:
        if tdbg == DEBUG_TYPE:
            dbg_valid = cnt
        cnt *= 2

    if dbg_valid == 0 and IMG_DBG != None:
        usage(f"Invalid debug_type Option {DEBUG_TYPE}")
        return 1
    else:
        DEVICE_DEBUG_TYPE = int(dbg_valid // 2)

    # --k
    SIGN_KEY = args.k

    # --l
    LOADADDR = args.l
    if LOADADDR is None:
        if path.C29_RBL_SOC == "tpr12":
            LOADADDR = "0x10200000"

        elif path.C29_RBL_SOC == "f29h85x":
            LOADADDR = "0x10001000"
        else:
            LOADADDR = "0x70002000"

    # --r
    ENC_RS = args.r

    # --s
    SWRV = args.s
    if SWRV is None:
        SWRV = 0

    # --u
    DEBUG_UID = args.u
    if DEBUG_UID is None:
        DEBUG_UID = 0

    # --x
    if args.x is not None:
        IMG_KD = 1
        KD_SALT = args.x

    # --y
    IMG_ENC = args.y
    if (IMG_ENC is not None) and (not IMG_ENC in VALID_ENC):
        usage(f"Invalid Encrypt Option {IMG_ENC}")
        return 1

    # --m
    KEY_LOCK = args.m

    # --o
    CRYPTO_LOCK = args.o

    return 0


def setupArgs() -> int:
    global BIN, SIGN_KEY, IMG_KD, KD_SALT_VAL, KD_SALT, LOADADDR
    global KD_INFO, KD_INFO_VAL, IMG_DBG, DEBUG_UID, DEVICE_UID, DEVICE_DEBUG_TYPE
    global IMG_ENC, IMG_ENC, ENC_BIN, BOOTCORE_ID, BOOTCORE_OPTS, CERT_TYPE, CERT, SHA_VAL, BIN_SIZE, ADDR
    global DIR_NAME, TEMP_X509
    if (BIN is None) or (not os.path.exists(BIN)):
        usage(f"Missing Input bin file")
        return 1

    DIR_NAME = os.path.dirname(BIN)
    TEMP_X509 = os.path.join(DIR_NAME, TEMP_X509)

    if SIGN_KEY is None:
        gen_rsakey()

    if IMG_KD == 1:
        KD_SALT_VAL = get_val_from_file(KD_SALT)
        print(f"KD_SALT = {KD_SALT_VAL}")
        if KD_INFO == None:
            print(f"Optional KD not specified")
            KD_INFO_VAL = 0
        else:
            print(f"Optional KD info specified")
            KD_INFO_VAL = get_val_from_file(KD_INFO)
        print(f"KD_INFO = {KD_INFO_VAL}")

    if IMG_DBG != None:
        print(f"\nDebug Enxtension is Enabled")
        if DEBUG_UID == None:
            print(f"SoC UID not specified for Debug Extension")
            return 1
        DEVICE_UID = get_val_from_file(DEBUG_UID)
        print(f"    UID =  {DEVICE_UID}")
        print(f"    DBG_TYPE =  {DEVICE_DEBUG_TYPE}")

    if IMG_ENC is not None:
        image_encrypt()
        BIN = ENC_BIN

    if CERT_SIGN == "C29":
        BOOTCORE_ID = 16
        CERT_TYPE = 1
        BOOTCORE_OPTS = 0
    else:
        LOADADDR = 0
        BOOTCORE_ID = 0
        CERT_TYPE = 2
        BOOTCORE_OPTS = 0

    CERT = f"{CERT_SIGN}-cert.bin"
    CERT = os.path.join(DIR_NAME, CERT)

    print(f"Computing {SHA} value for {BIN}")
    output = subprocess.check_output(
        f"openssl dgst -{SHA} -hex {BIN}", shell=True
    ).decode()
    pos = output.find("= ")
    if pos != -1:
        SHA_VAL = output[pos + 2 :].strip()
    BIN_SIZE = os.path.getsize(f"{BIN}")
    ADDR = "{:08x}".format(int(LOADADDR, 16))

    return 0


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
  1.3.6.1.4.1.294.1.3=ASN1:SEQUENCE:swrv
"""

g_x509_int_template_encryption = """
  1.3.6.1.4.1.294.1.4=ASN1:SEQUENCE:encryption
"""

g_x509_int_template_keyderivation = """
  1.3.6.1.4.1.294.1.5=ASN1:SEQUENCE:key_derivation
"""

g_x509_int_template_debug = """
  1.3.6.1.4.1.294.1.8=ASN1:SEQUENCE:debug
"""

g_x509_int_template_keylock = """
  1.3.6.1.4.1.294.1.11=ASN1:SEQUENCE:keylock
"""

g_x509_int_template_cryptolock = """
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
  shaType      =  OID:2.16.840.1.101.3.4.2.3
  shaValue     =  FORMAT:HEX,OCT:{TEST_IMAGE_SHA512}

 [ swrv ]
  swrv         =  INTEGER:{TEST_SWRV}
"""


g_x509_int_template_image_keylock = """
 [ keylock ]
  keylock         =  INTEGER:{KEY_LOCK_VAL}
"""


g_x509_int_template_image_cryptolock = """
 [ cryptolock ]
  cryptolock         =  INTEGER:{CRYPTO_LOCK_VAL}
"""

g_x509_int_template_image_enc = """
 [ encryption ]
  initalVector =  FORMAT:HEX,OCT:{TEST_IMAGE_ENC_IV}
  randomString =  FORMAT:HEX,OCT:{TEST_IMAGE_ENC_RS}
  iterationCnt =  INTEGER:{TEST_IMAGE_KEY_DERIVE_INDEX}
  salt         =  FORMAT:HEX,OCT:{TEST_IMAGE_KEY_DERIVE_SALT}
"""


g_x509_int_template_image_kd = """
 [ key_derivation ]
  salt         =  FORMAT:HEX,OCT:{TEST_IMAGE_KD_SALT}
  info         =  FORMAT:HEX,OCT:{TEST_IMAGE_KD_INFO}
"""


g_x509_int_template_image_debug = """
 [ debug ]
  debugUID     =  FORMAT:HEX,OCT:{TEST_DEVICE_UID}
  debugType    =  INTEGER:{TEST_DEVICE_DEBUG_TYPE}
  coreDbgEn    =  INTEGER:0
  coreDbgSecEn =  INTEGER:0
"""


def gen_cert():
    print(f"\n{CERT_SIGN} Certificate being generated: ")
    print(f"X509_CFG = {TEMP_X509}")
    print(f"KEY = {SIGN_KEY}")
    print(f"BIN = {BIN}")
    print(f"CERT TYPE = {CERT_SIGN}")
    print(f"CORE ID = {CERT_TYPE}")
    print(f"LOADADDR = 0x{ADDR}")
    print(f"IMAGE SIZE = {BIN_SIZE}\n")

    ret_cert = g_x509_int_template_header
    if IMG_ENC is not None:
        ret_cert += g_x509_int_template_encryption

    if IMG_KD == 1:
        ret_cert += g_x509_int_template_keyderivation

    if IMG_DBG is not None:
        ret_cert += g_x509_int_template_debug

    if KEY_LOCK is not None:
        ret_cert += g_x509_int_template_keylock

    if CRYPTO_LOCK is not None:
        ret_cert += g_x509_int_template_cryptolock

    ret_cert += g_x509_int_template_image_default.format(
        TEST_CERT_TYPE=CERT_TYPE,
        TEST_BOOT_CORE_ID=BOOTCORE_ID,
        TEST_BOOT_CORE_OPTS=BOOTCORE_OPTS,
        TEST_BOOT_ADDR=ADDR,
        TEST_IMAGE_LENGTH=BIN_SIZE,
        TEST_IMAGE_SHA512=SHA_VAL,
        TEST_SWRV=SWRV,
    )

    if KEY_LOCK is not None:
        ret_cert += g_x509_int_template_image_keylock.format(KEY_LOCK_VAL=KEY_LOCK)

    if CRYPTO_LOCK is not None:
        ret_cert += g_x509_int_template_image_cryptolock.format(
            CRYPTO_LOCK_VAL=CRYPTO_LOCK
        )

    if IMG_ENC is not None:
        ret_cert += g_x509_int_template_image_enc.format(
            TEST_IMAGE_ENC_IV=ENC_IV_VAL,
            TEST_IMAGE_ENC_RS=ENC_RS_VAL,
            TEST_IMAGE_KEY_DERIVE_INDEX=ENC_KD_INDEX_VAL,
            TEST_IMAGE_KEY_DERIVE_SALT=ENC_KD_SALT_VAL,
        )

    if IMG_KD == 1:
        ret_cert += g_x509_int_template_image_kd.format(
            TEST_IMAGE_KD_SALT=KD_SALT_VAL, TEST_IMAGE_KD_INFO=KD_INFO_VAL
        )

    if IMG_DBG is not None:
        ret_cert += g_x509_int_template_image_debug.format(
            TEST_DEVICE_UID=DEVICE_UID, TEST_DEVICE_DEBUG_TYPE=DEVICE_DEBUG_TYPE
        )

    with open(TEMP_X509, "w+") as fd:
        fd.write(textwrap.dedent(ret_cert))

    subprocess.check_output(
        f"openssl req -new -x509 -key {SIGN_KEY} -nodes -outform DER -out {CERT} -config {TEMP_X509} -{SHA} -days 365",
        shell=True,
    ).decode()
    return


g_x509_int_template_image_kd_noKDInfo = """
 [ key_derivation ]
  salt         =  FORMAT:HEX,OCT:{TEST_IMAGE_KD_SALT}
"""


def gen_cert_noKD():
    print(f"\n{CERT_SIGN} Certificate being generated: ")
    print(f"X509_CFG = {TEMP_X509}")
    print(f"KEY = {SIGN_KEY}")
    print(f"BIN = {BIN}")
    print(f"CERT TYPE = {CERT_SIGN}")
    print(f"CORE ID = {CERT_TYPE}")
    print(f"LOADADDR = 0x{ADDR}")
    print(f"IMAGE SIZE = {BIN_SIZE}\n")

    ret_cert = g_x509_int_template_header
    if IMG_ENC is not None:
        ret_cert += g_x509_int_template_encryption

    if IMG_KD == 1:
        ret_cert += g_x509_int_template_keyderivation

    if IMG_DBG is not None:
        ret_cert += g_x509_int_template_debug

    if KEY_LOCK is not None:
        ret_cert += g_x509_int_template_keylock

    if CRYPTO_LOCK is not None:
        ret_cert += g_x509_int_template_cryptolock

    ret_cert += g_x509_int_template_image_default.format(
        TEST_CERT_TYPE=CERT_TYPE,
        TEST_BOOT_CORE_ID=BOOTCORE_ID,
        TEST_BOOT_CORE_OPTS=BOOTCORE_OPTS,
        TEST_BOOT_ADDR=ADDR,
        TEST_IMAGE_LENGTH=BIN_SIZE,
        TEST_IMAGE_SHA512=SHA_VAL,
        TEST_SWRV=SWRV,
    )

    if KEY_LOCK is not None:
        ret_cert += g_x509_int_template_image_keylock.format(KEY_LOCK_VAL=KEY_LOCK)

    if CRYPTO_LOCK is not None:
        ret_cert += g_x509_int_template_image_cryptolock.format(
            CRYPTO_LOCK_VAL=CRYPTO_LOCK
        )

    if IMG_ENC is not None:
        ret_cert += g_x509_int_template_image_enc.format(
            TEST_IMAGE_ENC_IV=ENC_IV_VAL,
            TEST_IMAGE_ENC_RS=ENC_RS_VAL,
            TEST_IMAGE_KEY_DERIVE_INDEX=ENC_KD_INDEX_VAL,
            TEST_IMAGE_KEY_DERIVE_SALT=ENC_KD_SALT_VAL,
        )

    if IMG_KD == 1:
        ret_cert += g_x509_int_template_image_kd_noKDInfo.format(
            TEST_IMAGE_KD_SALT=KD_SALT_VAL,
        )

    if IMG_DBG is not None:
        ret_cert += g_x509_int_template_image_debug.format(
            TEST_DEVICE_UID=DEVICE_UID, TEST_DEVICE_DEBUG_TYPE=DEVICE_DEBUG_TYPE
        )

    with open(TEMP_X509, "w+") as fd:
        fd.write(textwrap.dedent(ret_cert))

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
        if KD_INFO_VAL == 0:
            print("\n[[Generating X509 certificate without KD Info]]\n")
            gen_cert_noKD()
        else:
            print("\n[[Generating X509 certificate with KD Info]]\n")
            gen_cert()

        print(f"\n[[CERT GENERATION SUCCESS: Generated {CERT}]]\n")

    else:
        print("\n[[Error generating X509 certificate for given binary file]]\n")
