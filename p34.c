/*
 * p34.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>

long int factorial(int n);

int main() {

    int A[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int B[10] = {0};
    long int i;
    for (i=0; i<10; i++) {
        B[i] = factorial(A[i]);
        printf("%ld\n", B[i]);
    }

    long int limit = factorial(9)*10;
    long long int tmp, tmpSum, sum;
    sum = 0;
    for (i=3; i<limit; i++) {
        tmp = i;
        tmpSum = 0;
        while (tmp > 0) {
            tmpSum += B[tmp%10];
            tmp /= 10;
        }
        if (tmpSum == i) {
            printf("%ld\n", i);
            sum += tmpSum;
        }
    }

    printf("sum is %lld\n", sum);


    return 0;
}

long int factorial(int n) {
    if (n == 0) {
        return 1;
    }

    if (n > 0) {
        if (n == 1) {
            return 1;
        } else {
            return n*factorial(n-1);
        }
    }
}

