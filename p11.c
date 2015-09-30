/*
 * p11.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * https://projecteuler.net/problem=11
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>

#define FILEPATH "E:/Works/demo/p11.txt"

int* initArr(int arr[20][20]);
int max(int a, int b, int c, int d);

int main() {

    int arr[20][20] = {0};
    long long int product[400] = {0};
    initArr(arr);
    int i, j, n, a, b, c, d;
    long long int mp;
    n = 0;
    mp = 0;
    for (i=0; i<20; i++) {
        for (j=0; j<20; j++) {
            printf("arr[%d][%d] is %d\n", i, j, arr[i][j]);

            if (j+3 < 20) {
                c = arr[i][j] * arr[i][j+1] * arr[i][j+2] * arr[i][j+3];
            } else {
                a = 0;
            }

            if (i+3 < 20 && j+3 < 20) {
                b = arr[i][j] * arr[i+1][j+1] * arr[i+2][j+2] * arr[i+3][j+3];
            } else {
                b = 0;
            }

            if (i+3 < 20) {
                a = arr[i][j] * arr[i+1][j] * arr[i+2][j] * arr[i+3][j];
            } else {
                c = 0;
            }

            if (j >=3 && i+3 < 20) {
                d = arr[i][j] * arr[i+1][j-1] * arr[i+2][j-2] * arr[i+3][j-3];
            } else {
                d = 0;
            }

            product[n] = max(a, b, c, d);

            (mp < product[n]) && (mp = product[n]);

            n++;
        }
    }
    for (i=0; i<400; i++) {
        printf("product[%d] is %d\n", i, product[i]);
    }

    printf("max is %d\n", mp);

    

    return 0;
}

int max(int a, int b, int c, int d) {
    int tmpa, tmpb;
    tmpa = a > b ? a : b;
    tmpb = c > d ? c : d;

    return tmpa > tmpb ? tmpa : tmpb;
}

int* initArr(int arr[20][20]) {
    FILE *fp;
    //使用fgets时, 指针必须初始化，不能仅仅声明
    char *line = (char *)malloc(4*sizeof(char));
    int i = 0;
    int j = 0;
    int num;

    if ((fp = fopen(FILEPATH, "r")) != NULL) {
        while (fgets(line, 4, fp) != NULL) {
            sscanf(line, "%d", &num);
            arr[i][j] = num;
            if (++j >= 20) {
                j = 0;
                i++;
            }
        }
        fclose(fp);
    } else {
        printf("File not found\n");
        exit;
    }
}

