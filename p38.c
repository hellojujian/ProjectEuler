/*
 * p38.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkPandigital(int n);

int main() {

    int limit = 9999;
    int i, maxn, maxi, tmp;

    maxn = 0;
    maxi = 0;
    for (i=1; i<=limit; i++) {
        if ((tmp = checkPandigital(i)) > 0) {
            (i>maxn) && (maxn = i) && (maxi = tmp);
            printf("i is %d, n is %d\n", i, tmp);
        }
    }

    printf("%d%d\n", maxn, maxi*maxn);

    return 0;
}

int checkPandigital(int n) {
    char map[9] = {0};
    int j, tmp, m;
    int flag = 1;
    for (j=1; j<=9; j++) {
        tmp = n * j;
        while (tmp > 0) {
            if (map[tmp%10-1]) {
                flag = 0;
                break;
            } else {
                map[tmp%10-1] = 1;
                tmp /= 10;
            }
        }

        int sum, i;
        sum = 0;
        for (i=0; i<9; i++) {
            if (map[i]) {
                sum++;
            }
        }
        if (!flag) {
            return 0;
        }
        if (flag && sum == 9) {
            return j;
        }
    }

    return 0;
}

