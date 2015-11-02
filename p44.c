/*
 * p44.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * 参考：
 * http://www.mathblog.dk/project-euler-44-smallest-pair-pentagonal-numbers/
 *
 * 一元二次方程的根为 (-b+(b^2-4ac)^0.5)/2
 * Pn = n(3n-1)/2  =>  n = (1+(1+24Pn)^0.5)/6
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int checkPentagon(long long int n);

int main() {
    int begin = clock();
    long long int i, j, Pi, Pj;
    i=1;
    int flag = 0;
    while (!flag) {
        i++;
        Pi = i*(3*i-1)/2;
        for (j=i-1; j>0; j--) {
            Pj = j*(3*j-1)/2;
            if (checkPentagon(Pi+Pj) && checkPentagon(Pi-Pj)) {
                flag = 1;
                break;
            }
        }
    }
    printf("i is %lld, j is %lld, D is %lld\n", i, j, i*(3*i-1)/2-j*(3*j-1)/2);

    int stop = clock();
    printf("time consumed is %dms\n", (stop-begin));
    return 0;
}

int checkPentagon(long long int n) {
    double tmp = (1+sqrt(1+24*n))/6;
    return tmp == (int)tmp;
}


