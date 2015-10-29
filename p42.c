/*
 * p42.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILEPATH "E:/Works/projectEuler/p042_words.txt"

void initArr(char Arr[][20]);

int main() {
    char Arr[2000][20] = {'\0'};
    initArr(Arr);
    int i, j, tmp, tmpLen, m, sum;
    int triangle[40] = {0};
    for (i=0; i<40; i++) {
        triangle[i] = i*(i+1)/2;
    }

    sum = 0;
    for (i=0; i<2000; i++) {
        if (strlen(Arr[i]) > 0) {
            printf("%s\n", Arr[i]);
            j = 0;
            tmp = 0;
            tmpLen = strlen(Arr[i]);
            for (j=0; j<tmpLen; j++) {
                tmp += Arr[i][j] - 64;
            }
            for (m=0; m<40; m++) {
                if (triangle[m] == tmp) {
                    sum++;
                    break;
                }
            }
        }
    }

    printf("sum is %d\n", sum);
    
    return 0;
}

void initArr(char Arr[][20]) {
    FILE *fp;
    char s[100000];
    fp = fopen(FILEPATH, "r+");
    fgets(s, 100000, fp);
    //printf("%s\n", s);
    fclose(fp);

    char *d = ",";
    char *p;

    int i = 0;
    p = strtok(s, d);
    sscanf(p, "\"%[A-Z]\"", Arr[i]);
    while(p) {
        i++;
        //printf("%s lenth is %d\n", str, strlen(str));
        p = strtok(NULL, d);
        if (p) {
            sscanf(p, "\"%[A-Z]\"", Arr[i]);
            //printf("%s lenth is %d\n", Arr[i], strlen(Arr[i]));
        }
    }
    printf("sum is %d\n", i);
}


