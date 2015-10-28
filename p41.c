/*
 * p41.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>

int checkPandigital(long int n, int len);
int isPrime(long int n);
long int ipow(int base, int p);

int main() {
    long int start = 987654321;
    int A[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i, n, ceil, floor, j;
    n = 0;
    for (i=8; i>=1; i--) {
        ceil = ipow(10, A[i]) - 1;
        floor = ipow(10, A[i-1]);
        for (j=ceil; j>floor; j-=2) {
            if (checkPandigital(j, A[i]) && isPrime(j)) {
                n = j;
                break;
            }
        }
        if (n) {
            break;
        }
    }

    printf("%ld\n", n);
    return 0;
}

long int ipow(int base, int p) {
    if (p <= 1) {
        return base;
    }
    long int i, sum;
    sum = base;
    for (i=1; i<p; i++) {
        sum *= base;
    }

    return sum;
}

int checkPandigital(long int n, int len) {
    char *map = NULL;
    map = (char *)calloc(len, sizeof(char));
    long int i = 10;
    while (n) {
        if (n % i == 0) {
            free(map);
            return 0;
        }
        if (!map[n%i-1]) {
            map[n%i-1] = 1;
            n /= i;
        } else {
            free(map);
            return 0;
        }
    }

    int sum = 0;
    for (i=0; i<len; i++) {
        if (map[i]) {
            sum++;
        }
    }
    if (sum == len) {
        free(map);
        return 1;
    }

    free(map);
    return 0;
}

int isPrime(long int n) {
    long int i, flag;
    flag = 1;
    for (i=2; (i*i)<(n+1); i++) {
        if (n%i == 0) {
            flag = 0;
            break;
        }
    }

    return flag;
}

