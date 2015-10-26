/*
 * p32.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 * 
 * 按照题目推理得
 *
 * 2位数 * 3位数 = 4位数   or  1位数 * 4位数 = 4位数
 *
 * 只有这种情况下3个数的位数和为9, 且这3个数都不含0
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>

int checkPandigital(int m, int n);

int main() {

    int i, j, sum;
    char map[10000] = {0};
    sum = 0;
    for (i=10; i<=99; i++) {
        for (j=100; j<=999; j++) {
            if (checkPandigital(i, j) && !map[i*j-1]) {
                sum += i*j;
                map[i*j-1] = 1;
                printf("i is%d, j is %d, product is %d\n", i, j, i*j);
            }
        }
    }

    for (i=1; i<=9; i++) {
        for (j=1000; j<=9999; j++) {
            if (checkPandigital(i, j) && !map[i*j-1]) {
                sum += i*j;
                map[i*j-1] = 1;
                printf("i is%d, j is %d, product is %d\n", i, j, i*j);
            }
        }
    }

    printf("sum is %d\n", sum);

    return 0;
}

int checkPandigital(int n, int m) {
    int A[3] = {n, m, n*m};
    char map[9] = {0};
    int i, flag, tmp;
    flag = 1;

    if (n%10 == 0 || m%10 == 0 || (n*m)%10 == 0) {
        return 0;
    }

    for (i=0; i<3; i++) {
        while (A[i] % 10) {
            if (map[A[i]%10 - 1]) {
                return 0;
            } else {
                map[A[i]%10 -1] = 1;
            }
            A[i] /= 10;
            if (A[i] >= 10 && A[i] % 10 == 0) {
                return 0;
            }
        }
    }

    return flag;
}

