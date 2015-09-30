/*
 * p13.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>

#define FILE_SRC "E:/Works/demo/p13.txt"

int* initArr(int arr[100][50]);

int main() {

    int arr[100][50] = {0};
    int res[105] = {0};
    int i, j, tmp;
    initArr(arr);

    for (i=0; i<100; i++) {
        for (j=0; j<50; j++) {
            printf("arr[%d][%d] is %d\n", i, j, arr[i][j]);
        }
    }

    for (j=49; j>=0; j--) {
        for (i=0; i<100; i++) {
            res[j+55] += arr[i][j];
        }
    }

    tmp = 0;
    for (i=104; i>0; i--) {
        printf("res[%d] is %d, ", i, res[i]);
        tmp = res[i];
        res[i] %= 10;
        printf("after process res[%d] is %d, ", i, res[i]);
        printf("before process res[%d] is %d, ", i-1, res[i-1]);
        if (tmp > 10) {
            res[i-1] += tmp/10;
            printf("after process res[%d] is %d\n", i-1, res[i-1]);
        }
    }

    for (i=0; i<105; i++) {
        printf("%d", res[i]);
    }

    return 0;
}

int* initArr(int arr[100][50]) {
    FILE *fp;
    char c;
    int i = 0;
    int j = 0;
    int num;

    if ((fp = fopen(FILE_SRC, "r")) != NULL) {
        for (i=0; i<100; i++) {
            for (j=0; j<50; j++) {
                arr[i][j] = fgetc(fp) - '0';
            }
            fgetc(fp);
        }
        fclose(fp);
    } else {
        printf("File not found\n");
        exit;
    }
    
}

