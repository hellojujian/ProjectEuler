/*
 * p28.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>

int main() {

    int N = 1001;
    int i, j;
    long long int sum, average, last;
    sum = 1;
    last = 1;
    for (i=3; i<=1001; i+=2) {
        average = (i*4-4) / 4;
        for (j=1; j<5; j++) {
            sum += last+j*average;
        }
        last += i*4 - 4;
    }

    printf("sum is %lld\n", sum);
    return 0;
}

