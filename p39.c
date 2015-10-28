/*
 * p39.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>

int main() {
    int S[1001] = {0};
    int a, b, c; //assume a<=b<c
    for (a=1; a<=1000; a++) {
        for (b=1; b<=1000; b++) {
            for (c=2; c<=1000; c++) {
                if (a<=b && b<=c && (a+b)>c && (a+b+c)<=1000 && a*a+b*b == c*c) {
                    S[a+b+c]++;
                }
            }
        }
    }

    int max, maxp;
    max = 0;
    maxp = 0;
    for (a=0; a<1001; a++) {
        if (S[a] > max) {
            max = S[a];
            maxp = a;
        }
        printf("S[%d] is %d\n", a, S[a]);
    }
    printf("maxp is %d\n", maxp);
    return 0;
}



