/*
 * p51.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * 分析可得，替换位置必定不包含最低位，若包含，则0-9中有5个偶数，剩下的5个
 * 奇数达不到8个的数目要求
 *
 * 通过全组合来实现替换
 * 参考: http://wuchong.me/blog/2014/07/28/permutation-and-combination-realize/
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

int replaceOneDigit(long long int n, int len);
long long int replaceSomeDigit(long long int n, int primeNum);

int main() {

    long long int n = 11;
    long long int res;
    for (n; ; n+=2) {
        if ((res = replaceSomeDigit(n, 8)) > 0) {
            printf("%lld\n", res);
            break;
        }
    }
    return 0;
}

long long int replaceSomeDigit(long long int n, int primeNum) {
    int i, j, p, q, tmp, len, m;
    char s[20], t[20];
    ltoa(n, s, 10);
    len = strlen(s);

    long long int primeCount, curMinPrime, totalMinPrime;
    primeCount = 0;
    totalMinPrime = 0;

    //对可能的位置进行全组合
    m = 1<<len;
    for (i=1; i<m; i++) {
        memset(t, 0, sizeof(t));
        for (j=0; j<len; j++) {
            tmp = i;
            if (tmp & (1<<j)) {
                //标记当前一轮选中的位置
                t[j] = '-';
            } else {
                t[j] = s[j];
            }
        }
        
        //从0-9进行依次替换
        primeCount = 0;
        curMinPrime = 0;
        for (p=0; p<=9; p++) {
            tmp = 0;
            if (p == 0 && t[0] == '-') {
                continue;
            }
            for (q=0; q<len; q++) {
                //若q在当前组合中
                if (t[q] == '-') {
                    tmp += p*ipow(10, len-1-q);
                } else {
                    tmp += (t[q]-'0')*ipow(10, len-1-q);
                }
            }
            //printf("t is %s, tmp is %d\n", t, tmp);
            if (isPrime(tmp)) {
                if (curMinPrime == 0) {
                    curMinPrime = tmp;
                } else {
                    curMinPrime = (curMinPrime < tmp ? curMinPrime : tmp);
                }
                primeCount++;
            }
            //printf("p is %d, primeCount is %d\n", p, primeCount);
        }
        if (primeCount == primeNum) {
            if (totalMinPrime == 0) {
                totalMinPrime = curMinPrime;
            } else {
                totalMinPrime = (totalMinPrime < curMinPrime ? totalMinPrime : curMinPrime);
            }
            printf("t is %s, ", t);
            printf("totalMinPrime is %lld\n", totalMinPrime);
        }
    }

    return totalMinPrime;
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

