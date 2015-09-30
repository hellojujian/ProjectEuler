/*
 * p19.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * https://projecteuler.net/problem=19
 *
 * 计算给定日期是星期几:  基姆拉尔森计算公式
 * W= (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7
 * 把一月和二月看成是上一年的十三月和十四月，例：如果是2004-1-10则换算成：2003-13-10来代入公式计算。
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>

int kim_larsson(int y, int m, int d);

int main() {
    int y, m, d, sum, tmp, i;
    d = 1;
    m = 1;
    y = 1901;
    sum = 0;
    
    for (y=1901; y<=2000; y++) {
        for (m=1; m<=12; m++) {
            if (m == 1 || m == 2) {
                tmp = kim_larsson(y-1, m+12, d);
            } else {
                tmp = kim_larsson(y, m, d);
            }

            (tmp == 0) && (sum++);
            /*
            if (tmp == 0) {
                printf("date is %d-%d-%d\n", y, m, d);
                exit(0);
            }
            */
        }

    }

    printf("there are %d sundays fall on the first of month\n", sum);
    return 0;
}

int kim_larsson(int y, int m, int d) {
    return (d + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400 + 1) % 7;
}


