/*
 * p47.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include "util.h"

int calcPrimeFactorNumber(long long int n);
long long int PRIME[10000] = {0};
void initPrime();

int main() {

    initPrime();
    printf("%lld\n", PRIME[9999]);

    long long int n;
    n = 2;
    while (1) {
        if (calcPrimeFactorNumber(n) == 4 && calcPrimeFactorNumber(n+1) == 4 && calcPrimeFactorNumber(n+2) == 4 && calcPrimeFactorNumber(n+3) == 4) {
            printf("n is %lld\n", n);
            break;
        }
        n++;
    }

    return 0;
}

int calcPrimeFactorNumber(long long int n) {
    if (n <= 2) {
        return 1;
    }
    long long int up = n/2;
    int i, count;
    i = count = 0;

    while (PRIME[i] <= up) {
        if (n%PRIME[i++] == 0) {
            count++;
        }
    }

    return count;
}

void initPrime() {
    long long int n = 2;
    int i = 0;
    while (i<10000) {
        if (isPrime(n)) {
            PRIME[i++] = n;
        }
        n++;
    }
}


