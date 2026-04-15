import os
import sys
import subprocess
import argparse
from pathlib import Path
import shutil

# Constants
SHA = 'sha512'
TMP_DIR = 'tmp'
FINALCERT = 'dual_cert_keyrev.bin'
FINALCERT_H = 'dual_cert_keyrev.h'

# File paths
SMPK = 'smpk.pem'
BMPK = 'bmpk.pem'
SMPKCERT = f'{TMP_DIR}/smpk-cert.bin'
BMPKCERT = f'{TMP_DIR}/bmpk-cert.bin'
SMPKTEMPLATE = f'{TMP_DIR}/smpk-template.txt'
BMPKTEMPLATE = f'{TMP_DIR}/bmpk-template.txt'

# Run a shell command and handle errors.
def run_command(command, check=True):

    result = subprocess.run(command, shell=True, text=True, capture_output=True)
    if check and result.returncode != 0:
        print(f"Command failed: {command}\nError: {result.stderr}")
        sys.exit(result.returncode)
    return result

#Remove temporary files.
def remove_files():

    try:
        shutil.rmtree(TMP_DIR)
    except OSError as e:
        print("Error: %s - %s." % (e.filename, e.strerror))
    

#Generate BMPK signed certificate binary.
def gen_bmpk_signed_cert_binary():
    with open(BMPKTEMPLATE, 'r') as file:
        template = file.read()
    template = template.replace('TEST_IMAGE_SHA512', SHA_VAL)
    template = template.replace('TEST_IMAGE_SIZE', SMPKCERT_SIZE)
    with open(BMPKTEMPLATE, 'w') as file:
        file.write(template)

    run_command(f"openssl req -new -x509 -key {BMPK} -nodes -outform DER -out {BMPKCERT} -config {BMPKTEMPLATE} -{SHA}")
    print("BMPK signed certificate generated")

#Generate SMPK signed certificate binary
def gen_smpk_signed_cert_binary():
    run_command(f"openssl req -new -x509 -key {SMPK} -nodes -outform DER -out {SMPKCERT} -config {SMPKTEMPLATE} -{SHA}")
    print("SMPK signed certificate generated")

#Generate SMPK certificate template.
def gen_smpk_cert_template():

    template = """
 [ req ]
 distinguished_name     = req_distinguished_name
 x509_extensions        = v3_ca
 prompt                 = no

 dirstring_type = nobmp

 [ req_distinguished_name ]
 C                      = US
 ST                     = SC
 L                      = Dallas
 O                      = Texas Instruments., Inc.
 OU                     = PBU
 CN                     = Albert
 emailAddress           = Albert@ti.com

 [ v3_ca ]
  basicConstraints = CA:true
"""
    with open(SMPKTEMPLATE, 'w') as file:
        file.write(template)

#Generate BMPK certificate template.
def gen_bmpk_cert_template():

    template = """
 [ req ]
 distinguished_name     = req_distinguished_name
 x509_extensions        = v3_ca
 prompt                 = no

 dirstring_type = nobmp

 [ req_distinguished_name ]
 C                      = US
 ST                     = SC
 L                      = Dallas
 O                      = Texas Instruments., Inc.
 OU                     = PBU
 CN                     = Albert
 emailAddress           = Albert@ti.com

 [ v3_ca ]
  basicConstraints = CA:true
  1.3.6.1.4.1.294.1.34=ASN1:SEQUENCE:image_integrity
"""
    with open(BMPKTEMPLATE, 'w') as file:
        file.write(template)
    
    image_integrity = """ 
 [ image_integrity ]
  shaType      =  OID:2.16.840.1.101.3.4.2.3
  shaValue     =  FORMAT:HEX,OCT:TEST_IMAGE_SHA512
  imageSize    =  INTEGER:TEST_IMAGE_SIZE
"""
    with open(BMPKTEMPLATE, 'a') as file:
        file.write(image_integrity)

def parse_arguments():
    
    parser = argparse.ArgumentParser(description='Create a dual signed certificate from the input SMPK/BMPK keys.')
    parser.add_argument('-s', '--smpk', required=True, help='Path to SMPK key')
    parser.add_argument('-b', '--bmpk', required=True, help='Path to BMPK key')
    return parser.parse_args()

def main():
    args = parse_arguments()
    global SMPK, BMPK
    SMPK = args.smpk
    BMPK = args.bmpk

    # Create temporary directory
    os.makedirs(TMP_DIR, exist_ok=True)

    try:
        gen_smpk_cert_template()
        gen_smpk_signed_cert_binary()

        # Compute SHA512 of the binary
        global SHA_VAL, SMPKCERT_SIZE
        result = run_command(f"openssl dgst -{SHA} -hex {SMPKCERT}", check=False)
        SHA_VAL = result.stdout.split()[-1]
        print(f"SMPK certificate hash: {SHA_VAL}")

        result = run_command(f"du -b {SMPKCERT}", check=False)
        SMPKCERT_SIZE = result.stdout.split()[0]
        print(f"SMPK certificate size: {SMPKCERT_SIZE}")

        gen_bmpk_cert_template()
        gen_bmpk_signed_cert_binary()

        # Combine certificates
        with open(FINALCERT, 'wb') as final_cert:
            with open(BMPKCERT, 'rb') as bmpk_cert:
                final_cert.write(bmpk_cert.read())
            with open(SMPKCERT, 'rb') as smpk_cert:
                final_cert.write(smpk_cert.read())
        
        print(f"Generated dual signed certificate binary: {FINALCERT}")

    finally:
        remove_files()

if __name__ == '__main__':
    main()