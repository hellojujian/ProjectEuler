/*
 * p51.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * 分析可得，替换位置必定不包含最低位，若包含，则0-9中有5个偶数，剩下的5个
 * 奇数达不到8个的数目要求
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int replaceOneDigit(long long int n, int len);

int main() {

    long long int n = 11;
    for (n; n<100; n+=2) {
        if (replaceOneDigit(n, 2) == 6) {
            printf("%lld\n", n);
        }
    }

    return 0;
}

int replaceOneDigit(long long int n, int len) {
    int i, j, k, sum, maxSum;
    long long int tmp;

    int *N = (int *)(calloc(len, sizeof(int)));
    int m = len-1;
    while (n) {
        N[m--] = n%10;
        n /= 10;
    }

    maxSum = 0;
    for (i=0; i<len-1; i++) {
        j = (i == 0 ? 1 : 0);
        sum = 0;
        for (j; j<=9; j++) {
            tmp = 0;
            //替换掉第i位数字
            for (k=0; k<len; k++) {
                if (k == i) {
                    tmp += j*ipow(10, len-1-k);
                } else {
                    tmp += N[k]*ipow(10, len-1-k);
                }
            }
            //printf("%lld\n", tmp);
            if (isPrime(tmp)) {
                sum++;
            }
        }

        maxSum = (sum > maxSum ? sum : maxSum);
        //printf("%dth digit replaced, %lld primes\n", i, sum);
    }
    
    free(N);

    return maxSum;

}

