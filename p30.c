/*
 * p30.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>

int ipow(int base, int p);

int main() {
    int A[10] = {0};
    long int i;
    for (i=0; i<10; i++) {
        A[i] = ipow(i, 5);
    }

    for (i=0; i<10; i++) {
        printf("A[%d] is %d\n", i, A[i]);
    }

    long int j, tmp, limit, tmpSum, sum;
    limit = ipow(9,5)*6;
    sum = 0;
    for (i=10; i<=limit; i++) {
        tmp = i;
        tmpSum = 0;
        while (tmp > 0) {
            j = tmp % 10;
            tmpSum += A[j];
            tmp /= 10;
        }
        if (i == tmpSum) {
            sum += i;
            printf("number is %ld\n", i);
        }
    }

    printf("sum is %ld", sum);
    return 0;
}

int ipow(int base, int p) {
    if (p <= 1) {
        return base;
    }
    int i, sum;
    sum = base;
    for (i=1; i<p; i++) {
        sum *= base;
    }

    return sum;
}

