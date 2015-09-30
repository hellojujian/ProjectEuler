/*
 * lis_uncontinuous.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * 这里的最长不降子序列 不一定是连续的
 * 
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>

#define ARRAY_LEN(array, len) {len = sizeof(array) / sizeof(array[0]);}
#define MAX(x, y) (x > y ? x : y)

int main() {

    int A[6] = {5, 3, 4, 8, 6, 7};
    int S[6] = {1};
    int len = 0;
    int i = 0;
    int j = 0;

    ARRAY_LEN(A, len);

    for (i=1; i<len; i++) {
        S[i] = 1;
        for (j=0; j<i; j++) {
            if (A[i] >= A[j] && S[j]+1 > S[i]) {
                S[i] = S[j] + 1;
            }
        }
    }

    for (i=0; i<len; i++) {
        printf("S[%d] is %d\n", i, S[i]);
    }

    return 0;
}


