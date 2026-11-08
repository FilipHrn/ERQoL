#pragma once
#include <stdbool.h>
#include <stddef.h>

bool path_next_to_module(void* module, const char* file_name, char* out, size_t out_size);