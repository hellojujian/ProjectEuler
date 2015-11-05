/*
 * p49.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include "util.h"

int check(int a, int b, int c, int len);

int main() {
    int start = 1001;
    int end = 9999;
    int i, j;

    for (i=start; i<=end; i+=2) {
        if (isPrime(i)) {
            for (j=i+2; j<=end; j+=2) {
                if (isPrime(j) && (2*j-i)<=end && isPrime(2*j-i) && check(i, j, 2*j-i, 4)) {
                    printf("%d %d %d\n", i, j, 2*j-i);
                }
            }
        }
    }

    printf("%d\n", check(1487, 4817, 8146, 4));

    return 0;
}

int check(int a, int b, int c, int len) {
    char mapa[10] = {0};
    while (a) {
        /*
        if (mapa[a%10]) {
            return 0;
        } else {
            mapa[a%10] = 1;
        }
        */
        mapa[a%10] = 1;
        a /= 10;
    }

    char mapb[10] = {0};
    while (b) {
        /*
        if (mapb[b%10]) {
            return 0;
        } else {
            mapb[b%10]++;
        }
        */
        mapb[b%10] = 1;
        b /= 10;
    }

    char mapc[10] = {0};
    while (c) {
        /*
        if (mapc[c%10]) {
            return 0;
        } else {
            mapc[c%10]++;
        }
        */
        mapc[c%10] = 1;
        c /= 10;
    }

    int i, sum;
    sum = 0;
    for (i=0; i<10; i++) {
        if (mapa[i] != mapb[i] || mapa[i] != mapc[i] || mapb[i] != mapc[i]) {
            return 0;
        }
    }

    return 1;
}


