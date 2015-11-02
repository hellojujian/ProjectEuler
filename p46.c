/*
 * p46.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include "util.h"

int checkGoldbach(long long int n);

int main() {
    printf("%lld\n", ipow(20, 3));
    long long int start, i, tmp, tmpFlag;
    start = 35;
    while (checkGoldbach(start)) {
        start += 2;
        printf("start is %lld\n", start);
    }
    
    printf("start is %lld\n", start);

    return 0;
}

int checkGoldbach(long long int n) {
    long long int i, tmp, tmpFlag;
    int flag = 0;
    while (!flag) {
        n += 2;
        i = 1;
        tmpFlag = 0;
        tmp = n-2*i*i;
        while(tmpFlag && tmp>0) {
            if (isPrime(tmp)) {
                tmpFlag = 1;
                break;
            } else {
                i++;
            }
        }
        if (!tmpFlag) {
            flag = 1;
        }
    }

    return flag;
}


