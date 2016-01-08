/*
 * p57.c
 * Copyright (C) 2016 jujian <jujian@diandong.com>
 *
 * gcc p57.c -o p57 -L../lib/gmp6/lib -lgmp
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <string.h>
#include "../lib/gmp6/include/gmp.h"

int checkDigit(mpz_t numerator, mpz_t denominator);

int main() {
    mpz_t numerator, denominator;
    mpz_init(numerator);
    mpz_init(denominator);

    mpz_set_ui(numerator, 3);
    mpz_set_ui(denominator, 2);

    int i, count = 0;
    char *num_s, *den_s;
    for (i=1; i<1000; i++) {
        checkDigit(numerator, denominator);
        num_s = mpz_get_str(NULL, 10, numerator);
        den_s = mpz_get_str(NULL, 10, denominator);
        if (strlen(num_s) > strlen(den_s)) {
            mpz_out_str(stdout, 10, numerator);
            printf(" / ");
            mpz_out_str(stdout, 10, denominator);
            printf("\n");
            count++;
        }
    }

    printf("count is %d\n", count);

    return 0;
}

int checkDigit(mpz_t numerator, mpz_t denominator) {
    mpz_t tmp;
    mpz_init(tmp);
    mpz_set(tmp, numerator);

    mpz_mul_ui(numerator, denominator, 2);
    mpz_add(numerator, numerator, tmp);
    mpz_add(denominator, denominator, tmp);

    return 1;
}

