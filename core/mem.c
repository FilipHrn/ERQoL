#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <string.h>

#include "mem.h"

#define MAX_PATTERN 128

static int hex_digit(char c) {
	if (c >= '0' && c <= '9') return c - '0';
	if (c >= 'A' && c <= 'F') return c - 'A' + 10;
	if (c >= 'a' && c <= 'f') return c - 'a' + 10;

	return -1;
}

static int parse_pattern(const char* pattern, uint8_t* bytes, uint8_t* mask) {
	int count = 0;
	const char* p = pattern;

	while (*p != '\0' && count < MAX_PATTERN) {
		if (*p == ' ') { p++; continue; }

		if (*p == '?') {
			bytes[count] = 0;
			mask[count] = 0;
			count++;
			p += (p[1] == '?') ? 2 : 1;
			continue;
		}

		int hi = hex_digit(p[0]);
		int lo = hex_digit(p[1]);
		if (hi < 0 || lo < 0) return -1;

		bytes[count] = (uint8_t)(hi * 16 + lo);
		mask[count] = 1;
		count++;
		p += 2;
	}

	return count;
}

static int find_text_section(uintptr_t module, uintptr_t* start, size_t* size) {
	IMAGE_DOS_HEADER* dos = (IMAGE_DOS_HEADER*)module;
	IMAGE_NT_HEADERS* nt = (IMAGE_NT_HEADERS*)(module + dos->e_lfanew);
	IMAGE_SECTION_HEADER* section = IMAGE_FIRST_SECTION(nt);

	for (WORD i = 0; i < nt->FileHeader.NumberOfSections; i++, section++) {
		if (memcmp(section->Name, ".text", 6) == 0) {
			*start = module + section->VirtualAddress;
			*size = section->Misc.VirtualSize;

			return 1;
		}
	}

	return 0;
}

uintptr_t mem_scan(uintptr_t module, const char* pattern) {
	uint8_t bytes[MAX_PATTERN];
	uint8_t mask[MAX_PATTERN];

	int parsed = parse_pattern(pattern, bytes, mask);
	if (parsed <= 0) return 0;
	size_t length = (size_t)parsed;

	uintptr_t start;
	size_t size;
	if (!find_text_section(module, &start, &size)) return 0;

	const uint8_t* code = (const uint8_t*)start;

	for (size_t i = 0; i + length <= size; i++) {
		size_t j = 0;
		while (j < length && (mask[j] == 0 || code[i + j] == bytes[j])) j++;
		if (j == length) return start + i;
	}

	return 0;
}

uintptr_t mem_resolve_rip(uintptr_t instruction, int disp_offset, int instruction_length) {
	if (instruction == 0) return 0;

	int32_t disp = *(int32_t*)(instruction + disp_offset);

	return instruction + instruction_length + disp;
}
