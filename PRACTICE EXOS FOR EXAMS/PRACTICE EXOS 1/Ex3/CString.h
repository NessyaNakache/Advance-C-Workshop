#pragma once

int MyStrlen(const char* str);


int MyStrlen(const char* start) {
    // NB: no nullptr checking!
    int cnt = 0;
    for (const char* end = start; *end != '\0'; ++end)
        ++cnt;
    return cnt;
}