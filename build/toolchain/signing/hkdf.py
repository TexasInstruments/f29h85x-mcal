#!/usr/bin/env python3

import hashlib
import hmac

hash_function = hashlib.sha512


def hmac_digest(key: bytes, data: bytes) -> bytes:
    return hmac.new(key, data, hash_function).digest()


def hkdf_extract(salt: bytes, ikm: bytes) -> bytes:
    if len(salt) == 0:
        salt = bytes([0] * hash_function().digest_size)
    return hmac_digest(salt, ikm)


def hkdf_expand(prk: bytes, length: int) -> bytes:
    t = b""
    okm = b""
    i = 0
    while len(okm) < length:
        i += 1
        t = hmac_digest(prk, t + bytes([i]))
        okm += t
    return okm[:length]


def hkdf(length: int,ikm: bytes, salt: bytes) -> bytes:
    prk = hkdf_extract(salt, ikm)
    return hkdf_expand(prk, length)