/*
 * p21.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 10000

long int checkDivisor(long int n);

int main() {
    unsigned char *map = NULL;
    map = (char *)malloc(LIMIT*sizeof(char));
    //0x0 : not checked
    //0x1 : checked, not amicable
    //0x2 : checked, is amicable
    memset(map, 0x0, LIMIT);

    long int i, tmp, sum;
    sum = 0;
    for (i=2; i<=LIMIT; i++) {
        if (map[i] == 0x0) {
            tmp = checkDivisor(i);
            if (tmp <= LIMIT) {
                if (checkDivisor(tmp) == i && tmp != i) {
                    map[i] = map[tmp] = 0x2;
                    sum += i + tmp;
                } else {
                    map[i] = map[tmp] = 0x1;
                }    
            }
        }
    }

    printf("sum of all the amicable numbers under 10000 is %ld\n", sum);

    return 0;
}

long int checkDivisor(long int n) {
    long int i, sum;
    sum = 1;

    for (i=2; (i*i)<(n+1); i++) {
        if (n%i == 0) {
            if (n/i == i) {
                sum += i;
            } else {
                sum += i + n/i;
            }
        }        
    }

    return sum;
}

