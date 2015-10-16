/* https://projecteuler.net/problem=24
 * p24.c
 * 
 * solution reference: http://taop.marchtea.com/01.06.html
 *
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <string.h>

void swap(char *a, char *b);
int allPermutation(char *str, int len);
void reverse(char *str, int start, int end);

int main() {

    char str[] = "0123456789";
    long int i = 1;
    int j;
    while (i < 1000000) {
        j = allPermutation(str, 10);
        if (j == 0) {
            i++;
        }
    }
    printf("%s\n", str);
    return 0;
}

void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int allPermutation(char *str, int len) {
    //step 1: 找到当前序列中最后一个升序的首位位置i
    int i;
    for (i=len-2; (i>=0) && str[i]>str[i+1]; --i) {
        ;
    }
    if (i < 0) {
        return -1;
    }

    //step 2: 找到序列中i右边最有一个比str[i]大的位置j
    int j;
    for (j=len-1; (j>i) && (str[i]>str[j]); --j) {
        ;
    }

    //step 3: 交换str[i], str[j];
    swap(&str[i], &str[j]);

    //step 4: 把str[i+1]...str[len]的部分反转
    reverse(str, i+1, len-1);

    return 0;
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

