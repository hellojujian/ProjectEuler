/*
 * p50.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include "util.h"

int main() {
    long long int i, j, sum, total, maxStart, maxEnd, maxLen;
    sum = 1;
    long long int P[100000] = {0};
    P[0] = 2;
    for (i=3; i<1000000; i+=2) {
        if (isPrime(i)) {
            P[sum++] = i;
        }
    }

    long long int tmpTotal, tmpLen;
    maxLen = 0;
    total = 0;
    for (i=0; i<sum; i++) {
        tmpTotal = P[i];
        tmpLen = 1;
        for (j=i+1; j<sum; j++) {
            tmpTotal += P[j];
            if (tmpTotal<1000000 && isPrime(tmpTotal)) {
                tmpLen = j-i+1;
                if (tmpLen >= maxLen) {
                    maxStart = i;
                    maxEnd = j;
                    maxLen = tmpLen;
                    total = tmpTotal;
                }
            }
        }
    }
    printf("there are %d primes below 1 million\n", sum);
    printf("start is %lld, end is %lld, len is %lld, value is %lld\n", maxStart, maxEnd, maxLen, total);
    return 0;
}



