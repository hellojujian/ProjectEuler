/*
 * bigint_cal.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 * What is the sum of the digits of the number 2^1000?
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>

int main() {
    int i = 0;
    int j = 0;
    int base = 2;
    int index = 1000;
    int res[1000] = {0};

    res[0] = 1;

    int pre, tmp;
    for (i=1; i<=index; i++) {
        pre = 0;
        tmp = 0;
        for (j=0; j<1000; j++) {
            tmp = res[j] * base;
            res[j] = (tmp + pre) % 10;
            pre = tmp >= 10 ? 1 : 0;
        }
    }

    int sum = 0;
    for (i=0; i<index; i++) {
        sum += res[i];
        printf("%d", res[i]);
    }

    printf("\nsum is %d\n", sum);

    return 0;
}

