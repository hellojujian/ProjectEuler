/*
 * sunday.c
 * Copyright (C) 2015 jujian <jujian@diandong.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <string.h>
#include <windows.h>

int strLocation(char *str, char c);
int checkSubstr(char *mstr, char *sstr);

int main() {

    DWORD start, stop;
    start = GetTickCount();
    printf("start time: %lld ms\n", start);

    char *mstr = "Then I realized that I should finish my even without my mother’s reminder Then I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my even without my mother’s reminderThen I realized that I should finish my home even without my mother’s reminder";
    char *substr = "home";
    int i, j, mlength, slength, pos, m_offset;
    i = 0;
    j = 0;
    pos = 0;
    m_offset = 0;
    mlength = strlen(mstr);
    slength = strlen(substr);
    while (mstr[i] != '\0') {
        //printf("i is %d, mstr[i] is %c, m_offset is %d\n", i, mstr[i], m_offset);
        j = 0;
        if (mstr[i] != substr[j]) {
            m_offset++;
        } else {
            while (mstr[i] == substr[j] && mstr[i] != '\0' && substr[j] != '\0') {
                i++;
                j++;
            }
            if (j == slength) {
                stop = GetTickCount();
                printf(" stop time: %lld ms\n", stop);
                printf("%d", m_offset);
                return 0;
            }

            if (pos = strLocation(substr, mstr[i+slength]) != -1) {
                m_offset += pos;
            } else {
                m_offset = (i + slength);
            }
        }
        i = m_offset;
    }

    printf("no match");

    return 0;
}

int strLocation(char *str, char c) {
    int pos = 0;
    while (*str++ != '\0') {
        if (*str == c) {
            return pos;
        }
        pos++;
    }

    return -1;
}
