/*
 * util.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "util.h"

long long int ipow(int base, int p) {
    if (p <= 0) {
        return base;
    }
    long long int i, sum;
    sum = base;
    for (i=1; i<p; i++) {
        sum *= base;
    }

    return sum;
}

long long int isPrime(long long int n) {
    if (n < 2) {
        return 0;
    }
    long long int i, flag;
    flag = 1;
    for (i=2; (i*i)<(n+1); i++) {
        if (n%i == 0) {
            flag = 0;
            break;
        }
    }

    return flag;
}

