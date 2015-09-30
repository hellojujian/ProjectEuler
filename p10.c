/*
 * p10.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 2000000

int isPrime(int n);

int main() {
    int begin = clock();
    unsigned char *bitmap = NULL;
    bitmap = (char *)malloc(LIMIT*sizeof(char));
    //0x0 : not checked
    //0x1 : checked, not prime
    //0x2 : checked, prime
    memset(bitmap, 0x0, LIMIT);
    int i, j;
    long long int sum;
    sum = 0;
    for (i=2; i<LIMIT; i++) {
        if (i > 2 && i % 2 == 0) {
            bitmap[i] =  0x1;
            continue;
        }
        j = 0;
        if (isPrime(i)) {
            bitmap[i] = 0x2;
            sum += i;
        }
    }

    printf("the sum of all primes below %d is %lld", LIMIT, sum);
    int end = clock();
    printf("time consumed is %dms\n", (end-begin));

    free(bitmap);
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

