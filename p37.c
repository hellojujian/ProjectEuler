/*
 * p37.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <time.h>

int isPrime(long long int n);
int leftCheck(long long int n);
int rightCheck(long long int n);
int noZero(long long int n);

int main() {
    long long int i;
    long long int sum = 0;
    int num = 0;
    
    long long int n = 13;
    clock_t start = clock();
    while (num < 11) {
        if (noZero(n) && leftCheck(n) && rightCheck(n) && isPrime(n)) {
            printf("n is %lld", n);
            sum += n;
            printf("sum is %lld\n", sum);
            num++;
        }
        if (n % 10 == 3) {
            n += 4;
        } else if (n % 10 == 7) {
            n += 6;
        }
    }

    printf("%d\n", leftCheck(5107));
    printf("%d\n", noZero(5107));
    return 0;
}

int noZero(long long int n) {
    long long int i, tmp;
    i = 10;
    while (n > 0) {
        tmp = n % i;
        if (!tmp) {
            return 0;
        }
        n /= i;
    }

    return 1;
}

int leftCheck(long long int n) {
    if (n < 10) {
        return 0;
    }
    int flag = 1;
    int tmp = 10;
    while (n%tmp != n) {
        if (!isPrime(n%tmp)) {
            flag = 0;
            break;
        } else {
            tmp *= 10;
        }
    }

    return flag;
}

int rightCheck(long long int n) {
    if (n < 10) {
        return 0;
    }
    int flag = 1;
    int tmp = 10;
    while (n/tmp > 0) {
        if (!isPrime(n/tmp)) {
            flag = 0;
            break;
        } else {
            tmp *= 10;
        }
    }

    return flag;
}

int isPrime(long long int n) {
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

