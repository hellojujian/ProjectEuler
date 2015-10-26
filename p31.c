/*
 * p31.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 * 
 * 依旧采用动态规划解决
 * 考虑dp[i][sum]为采用前i种硬币组成面额为sum的组合数
 * Ci为第i种硬币的面额
 * 则有 dp[i][sum] = dp[i-1][sum-0*Ci]
 *                 + dp[i-1][sum-1*Ci]
 *                 + ...
 *                 + dp[i-1][sum-sum/Ci*Ci] 
 * d[i][0] = 1 i>=1 
 * d[0][sum] = 0
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>

int main() {
    int sum = 200;
    int coin[8] = {1, 2, 5, 10, 20, 50, 100, 200};
    int maxNum[8] = {0};
    int i;
    for (i=0; i<8; i++) {
        maxNum[i] = sum/coin[i];
    }

    int dp[9][201] = {0};
    int j, tmpsum, coinNum;

    //只有面额为1的硬币时，无论何种sum，组合数都只有一种
    for (i=0; i<201; i++) {
        dp[1][i] = 1;
    }
    for (i=1; i<=8; i++) {
        dp[i][0] = 1;
    }

    for (i=2; i<=8; i++) {
        for (j=1; j<=200; j++) {
            for (coinNum=0; coinNum<=j/coin[i-1]; coinNum++) {
                dp[i][j] += dp[i-1][j-coinNum*coin[i-1]];
            }
        }
    }

    for (i=0; i<=200; i++) {
        printf("dp[3][%d] is %d\n", i, dp[3][i]);
    }

    printf("dp[8][200] is %d\n", dp[8][200]);
    return 0;
}

