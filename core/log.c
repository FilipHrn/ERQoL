#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <stdio.h>
#include <stdarg.h>

#include "log.h"

void log_msg(const char* fmt, ...)
{
    FILE* f = NULL;
    if (fopen_s(&f, "C:\\dev\\practice\\C\\ER_TestMod\\ER_TestMod\\log.txt", "a") != 0 || f == NULL) {
        return; // couldn't open the file, give up quietly
    }

    // Timestamp: [15:42:07]
    SYSTEMTIME st;
    GetLocalTime(&st);
    fprintf(f, "[%02d:%02d:%02d] ", st.wHour, st.wMinute, st.wSecond);

    // The message itself, printf-style
    va_list args;
    va_start(args, fmt);    // args now points at the first value after fmt
    vfprintf(f, fmt, args); // like fprintf, but takes the va_list
    va_end(args);           // always pair with va_start

    fputc('\n', f);
    fclose(f);
}