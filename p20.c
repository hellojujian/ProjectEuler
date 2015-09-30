/*
 * p20.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>

int main() {
    int res[200] = {0};

    int i, j, sum;

    sum = 0;
    res[0] = 1;
    for (i=2; i<=100; i++) {
        for (j=0; j<200; j++) {
            res[j] *= i;
        }
        for (j=0; j<200; j++) {
            if (res[j] > 10) {
                res[j+1] += res[j]/10;
                res[j] %= 10;
            }
        }
    }
    for (i=0; i<200; i++) {
        sum += res[i];
        printf("%d", res[i]);

    }
    printf("\nsum is %d\n", sum);
    return 0;
}



