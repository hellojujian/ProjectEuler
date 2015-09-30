/*
 * p36.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 1000000

int checkPalindrome(int n);
int checkPalindromeBin(int *n);
char* dec2bin(int n, int *);

int main() {
    int res, i, j, sum;
    int s[21] = {0};
    sum = 0;
    for (i=1; i<LIMIT; i++) {
        res = checkPalindrome(i);
        if (res) {
            dec2bin(i, s);
            if (checkPalindromeBin(s)) {
                sum += i;
            }
        }
    }

    printf("sum is %d\n", sum); //872187
    
    return 0;
}

int checkPalindrome(int n) {
    char *s = (char *)malloc(7*sizeof(char));
    int len;
    itoa(n, s, 10);
    len = strlen(s);
    int i, j, halflen;

    for (i=0, j=len-1; i<len; i++, j--) {
        if (s[i] != s[j]) {
            return 0;
        }
        if (j <= i) {
            return 1;
        }
    }
}

char* dec2bin(int n, int *s) {
    //int s[21] = {0};
    int i, j, len;
    len = 0;
    while (n > 0) {
        j = n%2;
        n = n/2;
        s[len] = j;
        len++;
    }
}

int checkPalindromeBin(int *n) {
    int i, j, flag;
    flag = j = 20;
    for (j=20; j>=0; j--) {
        if (n[j] == 1) {
            flag = j;
            break;
        }
    }

    for (i=0, j=flag; i<20; i++,j--) {
        if (n[i] != n[j]) {
            return 0;
        }
        if (j <= i) {
            return 1;
        }
    }
}

