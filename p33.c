/*
 * p33.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * 假设分子=10a+b，分母=10b+c ，a b c均为数字
 * 10a+b / 10b+c = a / c  =>  a*(10b+c) = c*(10a+b)
 * 简单推理可得 a b c均不能为0
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>

#define MIN(m, n) (m < n ? m : n)

int maxDivisor(int m, int n);

int main() {
    int a, b, c;

    int numerator, denominator;
    numerator = 1;
    denominator = 1;

    for (a=1; a<=9; a++) {
        for (b=1; b<=9; b++) {
            for (c=1; c<=9; c++) {
                if (a*(10*b+c) == c*(10*a+b) && a < c) {
                    printf("%d/%d is %d/%d\n", 10*a+b, 10*b+c, a, c);
                    numerator *= a;
                    denominator *= c;
                }    
            }
        }
    }

    printf("%d/%d is %d\n", numerator, denominator, maxDivisor(numerator, denominator));
    printf("denominator is %d\n", denominator/maxDivisor(numerator, denominator));


    return 0;
}

int maxDivisor(int m, int n) {
    if (m == n) {
        return m;
    }
    if (n == 1 || m == 1) {
        return 1;
    }

    int i, maxDivisor;
    maxDivisor = 1;
    for (i=2; i<=MIN(m, n); i++) {
        if (m%i == 0 && n%i == 0) {
            maxDivisor = i;
        }
    }

    return maxDivisor;
}


