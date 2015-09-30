/*
 * p3.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>

int isPrime(int n);

int main() {
    long long int n = 600851475143;
    long long int factor, i, j;
    factor = 0;
    for (i=2; (i*i)<(600851475144); i++) {
        if (n%i == 0 && isPrime(i)) {
            (factor < i) && (factor = i);
        }
    }

    printf("the max prime factor is %lld\n", factor);

    return 0;
}

int isPrime(int n) {
    int i, flag;
    flag = 1;
    for (i=2; (i*i)<(n+1); i++) {
        if (n%i == 0) {
            flag = 0;
            break;
        }
    }

    return flag;
}

