/*
 * p53.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * gcc p53.c -o p53 -L../lib/gmp6/lib -lgmp
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#include "../lib/gmp6/include/gmp.h"

long long int calcAllArrange(int n);
int calcOneNum(long long int n);
mp_bitcnt_t calcArrange(int n, mpz_t mn);

int main() {
    unsigned long int i, j, total;
    mpz_t n, res, limit, denominator, numerator, de1, de2;
    mpz_init(n);
    mpz_init(res);
    mpz_init(limit);
    mpz_init(denominator);
    mpz_init(numerator);
    mpz_init(de1);
    mpz_init(de2);

    mpz_set_str(limit, "1000000", 10);
    total = 0;

    for (i=1; i<=100; i++) {
        for (j=1; j<=i; j++) {
            mpz_fac_ui(numerator, i);
            mpz_fac_ui(de1, (i-j));
            mpz_fac_ui(de2, (j));
            mpz_mul(denominator, de1, de2);
            mpz_divexact(res, numerator, denominator);
            mpz_out_str(stdout, 10, res);
            printf("\n");
            if (mpz_cmp(limit, res) < 0) {
                total++;
            }
        }
    }

    printf("total is %d\n", total);

    /*
    calcArrange(25, a);

    int n, count;
    count = 0;
    for (n=1; n<=100; n++) {
        printf("n is %d\n", n);
        count += calcAllArrange(n);
    }

    printf("count is %d\n", count);
    */

    return 0;
}

//abandoned
mp_bitcnt_t calcArrange(int n, mpz_t mn) {
    mpz_t *count = (mpz_t *)calloc(n+1, sizeof(mpz_t));
    printf("%d", sizeof(count));
    printf("%d", sizeof(mp_bitcnt_t));
    mpz_t p, base, i, tmp_n, numberOne;
    mpz_init(i);
    mpz_init(p);
    mpz_init(base);
    mpz_init(tmp_n);
    mpz_init(numberOne);
    mpz_set_str(i, "1", 10);
    mpz_set_str(numberOne, "1", 10);
    mpz_set_str(base, "2", 10);
    //set p = 2^n
    mpz_pow_ui(p, base, n);

    mp_bitcnt_t k=0;
    for (i; mpz_cmp(i, p)<0; mpz_add(i, i, numberOne)) {
        k = mpz_popcount(i);
        mpz_add(count[k], count[k], numberOne);
    }
    mp_bitcnt_t j;
    for (j=0; j<=n; j++) {
        printf("count[%d] is ", j);
        mpz_out_str(stdout, 10, count[j]);
        printf("\n");
    }

    mpz_out_str(stdout, 10, p);

}

long long int calcAllArrange(int n) {
    long long int *count = (long long int *)calloc(n+1, sizeof(long long int));
    long long int p=1<<n;

    long long int i;
    int r, totalCount;
    totalCount = 0;
    for (i=1; i<p; i++) {
        r = calcOneNum(i);
        count[r]++;
    }
    for (i=0; i<=n; i++) {
        printf("count[%lld] is %lld\n", i, count[i]);
        if (count[i] > 1000000) {
            totalCount++;
        }
    }
    free(count);

    return totalCount;
}

int calcOneNum(long long int n) {
    int count = 0;
    while (n) {
        count++;
        n &= n-1;
    }

    return count;
}


