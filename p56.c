/*
 * p56.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * gcc p56.c -o p56 -L../lib/gmp6/lib -lgmp
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <string.h>
#include "../lib/gmp6/include/gmp.h"

int main() {
    int a, b, i, tmpSum, sum;
    char *str;
    mpz_t rop, base;
    mpz_init(rop);
    mpz_init(base);

    sum = 0;
    for (a=1; a<100; a++) {
        for (b=1; b<100; b++) {
            mpz_set_ui(base, a);
            mpz_pow_ui(rop, base ,b);
            //mpz_out_str(stdout, 10, rop);
            //printf("\n");
            str = mpz_get_str(NULL, 10, rop);
            i = 0;
            tmpSum = 0;
            while (*str != '\0') {
                tmpSum += *str - '0';
                *str++;
            }
            printf("%d\n", i);
            printf("tmpSum is %d\n", tmpSum);
            if (sum < tmpSum) {
                sum = tmpSum;
            }
        }
    }

    printf("sum is %d\n", sum);
    return 0;
}


