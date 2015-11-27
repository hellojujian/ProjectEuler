/*
 * p52.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>

int checkSameDigit(long long int n, int times);
int intlen(long long int n);

int main() {
    long long int n = 1;
    while (!checkSameDigit(n, 6)) {
        n++;
    }
    printf("n is %lld\n", n);

    return 0;
}

int checkSameDigit(long long int n, int times) {
    int i, j, nLen, lenSum, numCount;
    long long int tmp;
    lenSum = 0;
    for (i=1; i<=times; i++) {
        lenSum += intlen(n*i);
    }

    nLen = intlen(n);
    if (lenSum == nLen*times) {
        int *map = (int *)calloc(10, sizeof(int));
        for (i=1; i<=times; i++) {
            tmp = n*i;
            while (tmp) {
                map[tmp%10]++;
                tmp /= 10;
            }
            numCount = 0;
            for (j=0; j<10; j++) {
                if (map[j] == i) {
                    numCount++;
                }
            }
            if (numCount != nLen) {
                return 0;
            }
        }
        free(map);

        return 1;
    }

    return 0;
}

int intlen(long long int n) {
    if (n > 0) {
        int len = 0;
        while (n) {
            len++;
            n /= 10;
        }

        return len;
    }

    return 0;
}

