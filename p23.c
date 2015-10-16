/*
 * https://projecteuler.net/problem=23
 * p23.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <time.h>

int divisorSum(int n);

int main() {

    long long int sum;
    //最小的符合条件的数是24，因此初始化sum为1-23的和
    sum = 23*24/2;

    //上限
    int limit = 28123;
    int i, j, flag;
    int begin = clock();
    for (i=25; i<limit; i++) {
        //最小的abundant number是12
        j = 12;
        flag = 0;
        while (i-j >= j) {
            if (divisorSum(i-j) > (i-j) && divisorSum(j) > j) {
                flag++;
            }
            j++;
        }

        if (!flag) {
            printf("%d is\n", i);
            sum+= i;
        }
    }

    printf("sum of all the positive integers which cannot be written as the sum of two abundant numbers is %lld\n", sum);
    int end = clock();
    printf("time consumed is %dms\n", (end-begin));
    return 0;
}

int divisorSum(int n) {
    int i, sum;
    i = 2;
    sum = 1;
    while (i*i < n+1) {
        if (n % i == 0) {
            if (n/i == i) {
                sum += i;
            } else {
                sum += i + n/i;
            }
        }
        i++;
    }

    return sum;
}

