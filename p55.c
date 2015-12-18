/*
 * p55.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkPalindrome(long long int n, int nlen);

int main() {

    return 0;
}

int checkPalindrome(long long int n, int nlen) {
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

