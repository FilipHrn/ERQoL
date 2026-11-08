#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <string.h>

#include "path.h"

bool path_next_to_module(void* module, const char* file_name, char* out, size_t out_size) {
	DWORD length = GetModuleFileNameA(module, out, (DWORD)out_size);
	if (length == 0 || length >= out_size) return false;

	char* slash = strrchr(out, '\\');
	if (slash == NULL) return false;

	return strcpy_s(slash + 1, out_size - (size_t)(slash + 1 - out), file_name) == 0;
}