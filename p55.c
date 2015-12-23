/*
 * p55.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * gcc p55.c -o p55 -L../lib/gmp6/lib -lgmp
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/gmp6/include/gmp.h"

int checkLychrel(char *str);
int checkPalindrome(char *str);
void reverse(char *str, int start, int end);
void swap(char *a, char *b);

int main() {
    int n, count;
    count = 0;
    char str[5];

    for (n=1; n<10000; n++) {
        itoa(n, str, 10);
        if (checkLychrel(str)) {
            count++;
        }
    }

    printf("count is %d\n", count);

    return 0;
}

int checkLychrel(char *str) {
    mpz_t mA, mB;
    char *stra, *strb;
    int i, j;

    stra = str;
    mpz_init(mA);
    mpz_init(mB);

    for (i=1; i<50; i++) {
        mpz_set_str(mA, stra, 10);
        strb = mpz_get_str(NULL, 10, mA);
        reverse(strb, 0, strlen(strb)-1);
        mpz_set_str(mB, strb, 10);
        mpz_add(mA, mA, mB);
        stra = mpz_get_str(NULL, 10, mA);
        if (checkPalindrome(stra)) {
            printf("str is %s, stra is %s\n", str, stra);
            return 0;
        }
    }

    return 1;
}

int checkPalindrome(char *str) {
    int i, j, len;
    len = strlen(str);
    if (len <= 1) {
        return 0;
    }
    i = 0;
    j = i + len/2;
    for (i; i<j; i++) {
        if (str[i] != str[len-1-i]) {
            return 0;
        }
    }

    return 1;
}

void reverse(char *str, int start, int end) {
    if (start >= end) {
        return;
    }
    int i, j;
    i = start;
    j = i+(end-start)/2;
    for (i; i<=j; i++) {
        swap(&str[i], &str[end--]);
    }
}

void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

