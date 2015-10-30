/*
 * p43.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char *s);
int nextPermutation(char *str, int len);
void swap(char *a, char *b);
void reverse(char *str, int start, int end);
long long int llatoi(char *s);
long long int ipow(int base, int p);

int prime[8] = {1, 2, 3, 5, 7, 11, 13, 17};

int main() {
    long long int sum = 0;
    char begin[] = "1023456789";

    while (nextPermutation(begin, 10) != -1) {
        if (check(begin)) {
            printf("%s\n", begin);
            sum += llatoi(begin);
        }
    }
    printf("sum is %lld\n", sum);

    return 0;
}

long long int llatoi(char *s) {
    long long int res = 0;
    int len;
    len = strlen(s);
    while (*s != '\0') {
        res += (*s-48)*ipow(10, --len);
        s++;
    }
    printf("res is %lld\n", res);
    return res;
}

long long int ipow(int base, int p) {
    if (p == 1) {
        return base;
    }
    if (p <= 0) {
        return 1;
    }
    long long int i, sum;
    sum = base;
    for (i=1; i<p; i++) {
        sum *= base;
    }

    return sum;
}

int check(char *s) {
    int a, b, c, i, tmp;
    int flag = 1;
    for (i=1; i<=7; i++) {
        a = s[i]-48;
        b = s[i+1]-48;
        c = s[i+2]-48;
        tmp = a*100 + b*10 + c;
        if (tmp%prime[i]) {
            flag = 0;
            break;
        }
    }

    return flag;
}

int nextPermutation(char *str, int len) {
    //step 1: 找到当前序列中最后一个升序的首位位置i
    int i;
    for (i=len-2; (i>=0) && str[i]>str[i+1]; --i) {
        ;
    }
    if (i < 0) {
        return -1;
    }

    //step 2: 找到序列中i右边最后一个比str[i]大的位置j
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

void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
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

