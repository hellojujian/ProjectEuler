/*
 * p40.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>

int getDigit(int n, int len, int pos);

int main() {
    long int product = 1;
    long int i, sum;
    i = 1;
    sum = 0;
    int len[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    long int A[9] = {0, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
    char map[9] = {0};
    int p1, p2;
    p1 = 1;
    p2 = 1;
    while (i < 1000000) {
        if (i >= A[p2]) {
            p1++;
            p2++;
        }
        sum += len[p1];
        if (sum >= A[p2] && !map[p2]) {
            product *= getDigit(i, len[p1], (len[p1]-1) - (sum-A[p2]));
            printf("i is %d, sum is %d, start is %d, product is %d\n", i, sum, p1, product);
            map[p2] = 1;
        }

        i++;
    }

    printf("%ld\n", product);

    return 0;
}

int getDigit(int n, int len, int pos) {
    if (len <= 1 || pos < 0 || pos > len-1) {
        return 0;
    }
    int i, start;
    start = 1;
    for (i=1; i<=len-1; i++) {
        start *= 10;
    }
    int p = 0;

    while (n) {
        if (p < pos) {
            n %= start;
            start /= 10;
            p++;
        } else if (p == pos) {
            return n/start;
        }
    }

    return 0;
}


