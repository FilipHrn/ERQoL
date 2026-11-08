#pragma once

#include <stdint.h>

static inline void* mem_read_ptr(uintptr_t address) {
	return *(void**)address;
}