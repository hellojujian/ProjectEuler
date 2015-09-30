/*
 * bitprint.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>

void bitprint(int n);

int main() {
    int n = 34456;
    bitprint(n);

    return 0;
}

void bitprint(int n) {
    int m;
    m = n%10;
    n = (int) (n-m)/10;
    if (n > 0) {
        bitprint(n);
    }
    printf("%c\n", m+'0');
}


