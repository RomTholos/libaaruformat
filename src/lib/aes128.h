/*
 * This file is part of the Aaru Data Preservation Suite.
 * Copyright (c) 2019-2026 Natalia Portillo.
 *
 * SPDX-License-Identifier: MIT OR LGPL-2.1-or-later
 *
 * This file is dual-licensed. You may use, modify, and distribute it under
 * either the terms of the MIT license (see LICENSE-MIT) or the GNU Lesser
 * General Public License v2.1 or later (see LICENSE), at your option.
 */

#ifndef LIBAARUFORMAT_AES128_H
#define LIBAARUFORMAT_AES128_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief AES-128 CBC encrypt data in-place.
     *
     * @param key  16-byte encryption key.
     * @param iv   16-byte initialization vector (not modified).
     * @param data Buffer to encrypt in-place. Must be a multiple of 16 bytes.
     * @param length Number of bytes to encrypt. Must be a multiple of 16.
     */
    void aes128_cbc_encrypt(const uint8_t key[16], const uint8_t iv[16], uint8_t *data, uint32_t length);

    /**
     * @brief AES-128 CBC decrypt data in-place.
     *
     * @param key  16-byte decryption key.
     * @param iv   16-byte initialization vector (not modified).
     * @param data Buffer to decrypt in-place. Must be a multiple of 16 bytes.
     * @param length Number of bytes to decrypt. Must be a multiple of 16.
     */
    void aes128_cbc_decrypt(const uint8_t key[16], const uint8_t iv[16], uint8_t *data, uint32_t length);

#ifdef __cplusplus
}
#endif

#endif /* LIBAARUFORMAT_AES128_H */
