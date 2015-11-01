/*
 * p44.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Pn+1 - Pn == 3n+1
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int checkPentagon(long long int n);

int main() {
    int begin = clock();
    long long int A[100000] = {0};
    long long int i;
    for (i=0; i<100000; i++) {
        A[i] = i*(3*i-1)/2;
    }
    long long int a, b, c, d, flag;
    a = 1ll;
    b = 2ll;
    c = 3ll;
    d = 4ll;
    flag = 0;
    while (a<100000ll && b<99999ll) {
        printf("a is %lld, b is %lld, A[a] is %lld, A[b] is %lld\n", a, b, A[a], A[b]);
        if (A[a] + A[b] < A[b+1]) {
            a++;
            b = a+1ll;
            continue;
        } else if (!checkPentagon(A[a]+A[b])) {
        } else if (checkPentagon(A[a]+A[b])) { 
            printf("a is %lld, b is %lld\n", a, b);
            printf("checkPentagon is %lld\n", checkPentagon(A[a]+A[b]));
            if (checkPentagon(A[a]+2ll*A[b])) {
                printf("a is %d, b is %d, c is %d\n", a, b, checkPentagon(A[a]+A[b]));
                break;
            } else {
                b++;
            }
        }
    }

    /*
    printf("A[8718] is %lld, A[25295] is %lld, A[25296] is %lld\n", A[8718], A[25295], A[25296]);
    printf("%d\n", A[8718]+A[25295] < A[25296]);
    printf("%ld\n", checkPentagon(A[8718]+A[25295]));
    */

    int stop = clock();
    printf("time consumed is %dms\n", (stop-begin));
    return 0;
}

long long int checkPentagon(long long int n) {
    if (n == 1ll) {
        return 1ll;
    }
    long long int i, tmp, start;
    i = 1ll;
    start = i-1;
    tmp = start*(3*start-1)/2;
    while (tmp <= n) {
        if (tmp == n) {
            return start;
        } else {
            start++;
            tmp = start*(3*start-1)/2;
        }
    }

    return 0ll;
}


