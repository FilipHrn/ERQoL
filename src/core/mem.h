#pragma once

#include <stdint.h>

uintptr_t mem_scan(uintptr_t module, const char* pattern);
uintptr_t mem_resolve_rip(uintptr_t instruction, int disp_offset, int instruction_length);

static inline void* mem_read_ptr(uintptr_t address) {
	return *(void**)address;
}