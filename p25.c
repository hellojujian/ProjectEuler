/*
 * p25.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    long long int N;
    int i;
    int A1[1000] = {0};
    int A2[1000] = {0};
    int A3[1000] = {0};

    A1[0] = 1;
    A2[0] = 1;
    A3[0] = A1[0] + A2[0];
    N = 3;
    while (!A3[999]) {
        for (i=0; i<1000; i++) {
            A1[i] = A2[i];
        }
        for (i=0; i<1000; i++) {
            A2[i] = A3[i];
        }
        for (i=0; i<1000; i++) {
            A3[i] = A1[i] + A2[i];
        }
        for (i=0; i<1000; i++) {
            if (A3[i] >= 10) {
                A3[i+1] += A3[i]/10;
                A3[i] %= 10;
            }
        }
        N++;

    }

    printf("N is %lld\n", N);
    for (i=0; i<1000; i++) {
        printf("%d", A3[i]);
    }

    return 0;
}



