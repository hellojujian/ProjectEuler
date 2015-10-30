/*
 * p44.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>

int checkPentagon(long long int n);

int main() {
    long long int A[10000] = {0};
    printf("%d\n", sizeof(A));
    return 0;
}

int checkPentagon(long long int n) {
    if (n == 1ll) {
        return 1;
    }
    long long int i, start, tmp;
    i = 1ll;
    start = i-1;
    tmp = start*(3*start-1)/2;
    while (tmp <= n) {
        if (tmp == n) {
            return 1;
        } else {
            start++;
            tmp = start*(3*start-1)/2;
        }
    }

    return 0;
}


