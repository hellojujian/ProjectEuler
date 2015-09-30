/*
 * p21.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 10000

int main() {
    unsigned char *map = NULL;
    map = (char *)malloc(LIMIT*sizeof(char));
    //0x0 : not checked
    //0x1 : checked, not amicable
    //0x2 : checked, is amicable
    memset(map, 0x0, LIMIT);

    return 0;
}



