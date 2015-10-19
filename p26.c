/*
 * p26.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>

int calcCycle(int n);

int main() {
    int A[1000] = {0};
    int i, maxi, maxlen, tmp;
    maxi, maxlen = 1;
    for (i=2; i<1000; i++) {
        tmp = calcCycle(i);
        if (tmp > maxlen) {
            maxi = i;
            maxlen = tmp;
        }
    }

    printf("value is %d, len is %d\n", maxi, maxlen);
    return 0;
}

int calcCycle(int n) {
    int *map = (int *)calloc(n, sizeof(int));
    int len = 0;
    int remainder = 0;
    remainder = 10 % n;
    while(remainder) {
        if (!map[remainder-1]) {
            map[remainder-1] = 1;
            len++;
            remainder = remainder * 10 % n;
        } else {
            break;
        }
    }
    return len;
}

