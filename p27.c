/*
 * p27.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>

long long int isPrime(long long int n);
long long int nextPrime(long long int n);

int main() {
    long int i, j, a, b, maxNum, tmpNum, coefficientA, coefficientB;
    maxNum = tmpNum = 0;
    for (i=3; i<1000; i+=2) {
        if (isPrime(i)) {
            b = i;
            for (a=-999; a<1000; a+=2) {
                if (a > -1-b) {
                    j = 1;
                    tmpNum = 1;
                    while (isPrime(j*j + a*j +b)) {
                        j++;
                        tmpNum++;
                    }
                    if (tmpNum > maxNum) {
                        maxNum = tmpNum;
                        coefficientA = a;
                        coefficientB = b;
                    }
                }
            }
        }
    }

    printf("a is %d, b is %d, product is %ld, maxNum is %d\n", coefficientA, coefficientB, coefficientA*coefficientB, maxNum);
    printf("%d\n", nextPrime(53));
    return 0;
}

long long int isPrime(long long int n) {
    if (n < 2) {
        return 0;
    }
    long long int i, flag;
    flag = 1;
    for (i=2; (i*i)<(n+1); i++) {
        if (n%i == 0) {
            flag = 0;
            break;
        }
    }

    return flag;
}

long long int nextPrime(long long int n) {
    if (n % 2 == 0) {
        ++n;
    } else {
        n += 2;
    }
    while(!isPrime(n)) {
        n += 2;
    }

    return n;
}

