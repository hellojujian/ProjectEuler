/*
 * p35.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * https://projecteuler.net/problem=35
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define LIMIT 1000000

int rotate(int n);
int isPrime(int n);

int main() {
    int begin = clock();
    unsigned char *bitmap = NULL;
    bitmap = (char *)malloc(LIMIT*sizeof(char));
    //0x0 : not checked
    //0x1 : checked, not prime
    //0x2 : checked, prime
    memset(bitmap, 0x0, LIMIT);

    int i, j;
    for (i=2; i<LIMIT; i++) {
        if (i > 2 && i % 2 == 0) {
            bitmap[i] =  0x1;
            continue;
        }
        j = 0;
        if (isPrime(i)) {
            bitmap[i] = 0x2;
        }
    }

    int sum, tmp;
    sum = 0;
    int flag;
    for (i=2; i<LIMIT; i++) {
        j = 0;
        flag = 1;
        if (bitmap[i] == 0x2) {
            j++;
            tmp = i;
            while ((tmp = rotate(tmp)) != i) {
                if (bitmap[tmp] != 0x2) {
                    flag = 0;
                    break;
                }
                if (bitmap[tmp] == 0x2) {
                    if (tmp > i) {
                        j++;
                    } else {
                        j--;
                    }
                }
            }
            if (flag) {
                //printf("prime is %d\n", i);
                sum += j;
            }
        }
    }
    //printf("below %d the num of prime is %d\n", LIMIT, j);
    printf("while the num of circular prime is %d\n", sum); // 55

    int end = clock();
    printf("time consumed is %dms\n", (end-begin));

    free(bitmap);

    return 0;
}

int rotate(int n) {
    int count, i;

    count = 0;
    i = 1;
    do {
        count++;
        i *= 10;
    } while (n >= i);
    
    int res = n % 10;
    for (i=0; i<count-1; i++) {
        res *= 10;
    }
    return res + (n/10);
}

int isPrime(int n) {
    int i, flag;
    flag = 1;
    for (i=2; (i*i)<(n+1); i++) {
        if (n%i == 0) {
            flag = 0;
            break;
        }
    }

    return flag;
}

