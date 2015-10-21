/*
 * p29.c
 *
 * 考虑质因数分解
 * 推导出10以下质数的乘积组合作为底数来推算有多少重复的数
 *
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>

int ipow(int base, int p);

int main() {
    int A[6] = {2, 3, 5, 7, 6, 10};
    int sum = 0;
    int i, j, tmpSum;

    for (i=0; i<6; i++) {
        j = 2;
        tmpSum = 0;
        while (ipow(A[i], j) <= 100) {
            tmpSum = 100/j - 1;
            sum += tmpSum;
            j++;
        }
    }

    //以下是以上计算未纳入的部分
    // 4^(51~100) = 2^(102~200) step=2
    // 8^(34~100) = 2^(102~300) step=3
    //16^(26~100) = 2^(104~400) step=4
    //32^(21~100) = 2^(105~500) step=5
    //64^(17~100) = 2^(102~600) step=6
    // 9^(51~100) = 3^(102~200) step=2
    //27^(34~100) = 3^(102~300) step=3
    //81^(26~100) = 3^(104~400) step=4
    int A2[5][3] = {
        {102, 200, 2},
        {102, 300, 3},
        {104, 400, 4},
        {105, 500, 5},
        {102, 600, 6},
    };
    int A3[3][3] = {
        {102, 200, 2},
        {102, 300, 3},
        {104, 400, 4},
    };
    char map[601] = {0};
    int start, end, step, repeat;
    repeat = 0;
    for (i=0; i<5; i++) {
        start = A2[i][0];
        end = A2[i][1];
        step = A2[i][2];
        for (j=start; j<=end; j+=step) {
            if (map[j] == 0) {
                map[j] = 1;
            } else if (map[j] == 1) {
                repeat++;
            }
        }
    }

    char map1[401] = {0};
    for (i=0; i<3; i++) {
        start = A3[i][0];
        end = A3[i][1];
        step = A3[i][2];
        for (j=start; j<=end; j+=step) {
            if (map1[j] == 0) {
                map1[j] = 1;
            } else if (map1[j] == 1) {
                repeat++;
            }
        }
    }

    printf("repeat is %d\n", repeat);

    printf("sum is %d\n, there is %d distinct terms\n", sum, 99*99-sum-repeat);


    return 0;
}

int ipow(int base, int p) {
    if (p <= 1) {
        return base;
    }
    int i, sum;
    sum = base;
    for (i=1; i<p; i++) {
        sum *= base;
    }

    return sum;
}

