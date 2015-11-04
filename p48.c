/*
 * p48.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>

void add();
void initB(int base);
void multi(int n);

int A[11] = {0};
int B[11] = {0};

int main() {
    int i, j;
    long long int sum, tmp;
    sum = tmp = 0;
    for (i=1; i<=1000; i++) {
        initB(i);
        for (j=1; j<i; j++) {
            multi(i);
        }
        add();
    }
    
    for (i=9; i>=0; i--) {
        printf("%d", A[i]);
    }
    return 0;
}

//只计算最低10位即可
void multi(int n) {
    int i, j, k, tmp, len;
    len = 0;
    tmp = n;
    while (tmp) {
        tmp /= 10;
        len++;
    }

    int C[len];
    tmp = n;
    i = 0;
    while (tmp) {
        C[i++] = tmp%10;
        tmp /= 10;
    }
    int tmpB[12] = {0};
    int tmpStart = 0;
    for (i=0; i<len; i++) {
        tmpStart = i;
        for (j=0; j<=10; j++) {
            tmpB[tmpStart++] += B[j]*C[i];
            for (k=0; k<=10; k++) {
                if (tmpB[k] >= 10) {
                    tmpB[k+1] += tmpB[k]/10;
                    tmpB[k] %= 10;
                }
            }
        }
    }
    for (i=0; i<=10; i++) {
        B[i] = tmpB[i];
    }
}

void initB(int base) {
    int i;
    i = 0;
    while (base) {
        B[i++] = base % 10;
        base /= 10;
    }
    for (i; i<19; i++) {
        B[i] = 0;
    }
}

void add() {
    int i;
    for (i=0; i<=10; i++) {
        A[i] += B[i];
    }
    for (i=0; i<=10; i++) {
        if (A[i] >= 10) {
            A[i+1] += A[i]/10;
            A[i] %= 10;
        }
    }
}


