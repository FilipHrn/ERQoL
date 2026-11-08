#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <stdio.h>
#include <stdarg.h>

#include "log.h"
#include "path.h"
#include "mod.h"

#ifdef _DEBUG
#define LOG_FILE "..\\..\\" MOD_NAME "_log.log"
#else
#define LOG_FILE MOD_NAME "_log.log"
#endif

static char log_path[MAX_PATH];

void log_init(void* module) {
    if (!path_next_to_module(module, LOG_FILE, log_path, sizeof(log_path))) {
        log_path[0] = '\0';
        return;
    }

    FILE* f = NULL;
    if (fopen_s(&f, log_path, "w") == 0 && f != NULL) fclose(f);
}

void log_msg(const char* fmt, ...)
{
    if (log_path[0] == '\0') return;

    FILE* f = NULL;
    if (fopen_s(&f, log_path, "a") != 0 || f == NULL) {
        return;
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