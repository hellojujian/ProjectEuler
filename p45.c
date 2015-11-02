/*
 * p45.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <math.h>


int checkPentagon(long long int n);
int checkHexagon(long long int n);

int main() {
    long long int i, n;
    int flag = 0;
    i = 285;
    while (!flag) {
        i++;
        n = i*(i+1)/2;
        if (checkPentagon(n) && checkHexagon(n)) {
            flag = 1;
        }
    }

    printf("i is %lld, n is %lld\n", i, n);

    return 0;
}

int checkPentagon(long long int n) {
    double tmp = (1+sqrt(1+24*n))/6;
    return tmp == (int)tmp;
}

int checkHexagon(long long int n) {
    double tmp = (1+sqrt(1+8*n))/4;
    return tmp == (int)tmp;
}

