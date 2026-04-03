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

#include <stddef.h>
#include <stdint.h>

#ifdef _WIN32
#include <windows.h>

uint64_t get_filetime_uint64()
{
    FILETIME   ft;
    SYSTEMTIME st;
    GetSystemTime(&st);  // UTC time
    SystemTimeToFileTime(&st, &ft);
    return ((uint64_t)ft.dwHighDateTime << 32) | ft.dwLowDateTime;
}

#else
#include <sys/time.h>

/**
 * @brief Gets the current time as a 64-bit FILETIME value.
 *
 * Returns the current system time as a 64-bit value compatible with Windows FILETIME (number of 100-nanosecond
 * intervals since January 1, 1601 UTC).
 *
 * @return The current time as a 64-bit FILETIME value.
 */
uint64_t get_filetime_uint64()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);  // seconds + microseconds since 1970

    const uint64_t epoch_diff = 11644473600ULL;  // seconds between 1601 and 1970
    uint64_t       ft         = (tv.tv_sec + epoch_diff) * 10000000ULL + tv.tv_usec * 10;
    return ft;
}
#endif
