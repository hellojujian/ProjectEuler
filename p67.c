/*
 * maximum_path_sum.c
 * Copyright (C) 20100 jujian <jujian@diandong.com>
 *
 * https://projecteuler.net/problem=18
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>

#define FILEPATH "E:/Works/demo/p67.txt"
#define MAX(x, y) (x > y ? x : y)

int* initArr();

int main() {
    int arr[100][100] = {0};
    initArr(&arr);
    int i = 0;
    int j = 0;

    int MaxPath[100][100] = {0};

    MaxPath[0][0] = arr[0][0];

    for (i=1; i<100; i++) {
        for (j=0; j<i+1; j++) {
            if (j == 0) {
                MaxPath[i][j] = MaxPath[i-1][j] + arr[i][j];
            } else if (j == i) {
                MaxPath[i][j]  = MaxPath[i-1][j-1] + arr[i][j];
            } else {
                MaxPath[i][j] = MAX(MaxPath[i-1][j-1], MaxPath[i-1][j]) + arr[i][j];
            }
        }
    }

    for (i=0; i<100; i++) {
        for (j=0; j<100; j++) {
            printf("arr[%d][%d] is %d\n", i, j, arr[i][j]);
        }
    }

    int max = MaxPath[99][0];
    for (i=0; i<100; i++) {
        (max < MaxPath[99][i]) &&  (max = MaxPath[99][i]);
    }
    printf("max value is %d\n", max);


    return 0;
}

int* initArr(int arr[100][100]) {
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
            if (++j > i) {
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
