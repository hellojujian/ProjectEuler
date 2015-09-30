/*
 * p17.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * https://projecteuler.net/problem=17
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <string.h>

int main() {
    char *map[20] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                     "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                     "eighteen", "nineteen"};
    int len_map[20] = {0};
    int i;
    for (i=0; i<20; i++) {
        len_map[i] = strlen(map[i]);
    }

    char *map2[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    int len_map2[10] = {0};
    for (i=0; i<10; i++) {
        len_map2[i] = strlen(map2[i]);
        printf("len_map2[%d] is %d\n", i, len_map2[i]);
    }

    int tmp1, tmp2;
    long long int sum;
    sum = 0;
    for (i=1; i<1000; i++) {
        //先判断十位数字是否为1
        tmp1 = i % 100;
        if (tmp1 < 20) {
            sum += len_map[tmp1];
        } else {
            if (tmp1 % 10 == 0) {
                sum += len_map2[tmp1/10];
            } else {
                tmp2 = tmp1 % 10;
                sum += len_map[tmp2] + len_map2[(tmp1-tmp2)/10];
            }
            
        }

        tmp1 = i / 100;
        if (tmp1 > 0) {
            if (i % 100 == 0) {
                sum += len_map[tmp1] + 7; //example: one hundred
            } else {
                sum += len_map[tmp1] + 7 + 3; //example: one hundred and xx
            }
        }
    }

    sum += 11; //add length of one thousand 

    printf("from 1 to 1000 the count of letters is %d\n", sum);

    return 0;
}



