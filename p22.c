/*
 * p22.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILEPATH "E:/Works/projectEuler/p022_names.txt"

void initArr(char Arr[][20]);
int sort_function(const void *a, const void *b);

int main() {
    char Arr[5163][20] = {"\0"};
    initArr(Arr);

    int i, j, len, tmp;
    long long int sum;
    sum = 0;

    qsort((void *)Arr, 5163, sizeof(Arr[0]), sort_function); 
    for (i=0; i<5163; i++) {
        printf("%s\n", Arr[i]); 
        j = 0;
        tmp = 0;
        len = strlen(Arr[i]);
        for (j=0; j<len; j++) {
            tmp += Arr[i][j] - 64;
        }
        sum += tmp * (i+1);
        printf("%d\n", tmp); 
    }

    printf("sum of all length is %lld", sum);
    return 0;
}

int sort_function(const void *a, const void *b) {
    return (strcmp(a, b));
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

