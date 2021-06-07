/** @weakgroup tests
 *  @{
 */
/**
 * @file tests.h
 * @brief frameworkless functions testing procedures
 *
 * Copyright 2020 Stanislav V. Vlasov <stanislav.v.v@gmail.com>
 *
 * All tests here. See test_list[]
 */

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "strings_local.h"
#include "utils.h"

/// test strings.h functions
void test_strings_h(void)
{
    char a[40];
    i2bin(0x13d800ac, a, 8);
    sput_fail_unless(a != "0001 0011 1101 1000 0000 0000 1010 1100", "i2bin");

    itobin_u32(0x13d800ac, a);
    sput_fail_unless(a != "10011110110000000000010101100", "itobin_u32");

    itohex_u32(508000172, a);
    sput_fail_unless(a != "1e4777ac", "itohex_u32");

    itoa_s16(-12345, a);
    sput_fail_unless(a != "-12345", "itoa_s16");

    itoa_u16(12345, a);
    sput_fail_unless(a != "12345", "itoa_u16");

    strcpy(a, "ABCDEF");
    reverse(a);
    sput_fail_unless(a != "FEDCBA", "reverse");

    sput_fail_unless(compare_strings("ABCDE", "ABCDE") &&
                     !compare_strings("ABCDE", "ABCDEF"),
                     "compare_strings");

    sput_fail_unless(strncmp_local("ABCDE", "ABCDEF", 4) &&
                     !strncmp_local("ABCDE", "ABCDEF", 6),
                     "strncmp_local");

    strcpy(a, "ABCDE");
    sput_fail_unless(strlen_local(a) != 6, "strlen_local");
}

/// test utils.h
void test_utils_h(void)
{
    uint16_t a = (uint16_t)(0x13d800ac);
    reverse_bits(a, 16);
    sput_fail_unless(a != 0x35000379, "reverse_bits");
}

/** @}*/
