/*
 * min_coin_num.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * 有1,3,5面额的硬币若干，求凑够N元所需最少硬币数
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>

int min(int a, int b, int c);


int main() {
    int coin[3] = {1, 3, 5};
    //凑够53元
    int sum = 53;
    int i = 0;
    int j = 0;

    int S[54] = {0};
    int tmp_s[3] = {0};

    for (i=1; i<=53; i++) {
        //初始化每轮开始计算时的 3种币额下的硬币数
        for (j=0; j<3; j++) {
            tmp_s[j] = 0;
        }
        for (j=0; j<3; j++) {
            if (coin[j] <= i) {
                tmp_s[j] = S[i-coin[j]] + 1;
            }
        }
        S[i] = min(tmp_s[0], tmp_s[1], tmp_s[2]);
    }

    for (i=0; i<54; i++) {
        printf("S[%d] is %d\n", i, S[i]);
    }

    return 0;
}

int min(int a, int b, int c) {
    if (b > 0) {
        if (c > 0) {
            int tmp = a < b ? a : b;
            return tmp < c ? tmp : c;
        } else {
            return a < b ? a : b;
        }
    } else {
        return a;
    }
}

