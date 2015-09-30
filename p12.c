/*
 * p12.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>

long long int divisorNum(long long int n);

int main() {
    long long int n, sum, i, j, tmp;
    n = 2;
    sum = 1;
    i = 2;
    j = 3;
    while (sum < 500) {
        if ((tmp = divisorNum(j)) > sum) {
            sum = tmp;
            n = j;
        }
        i++;
        j = i * (i+1) / 2;
    }
        

    printf("%d, %d\n", n, sum);

    return 0;
}

long long int divisorNum(long long int n) {
    long long int i, sum;
    sum = 1;
    for (i=2; (i*i)<(n+1); i++) {
        if (n%i == 0 && n/i != i) {
            sum += 2;
        }
    }

    return sum;
}

