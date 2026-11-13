#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define ARRAY_COUNT(a) (sizeof(a) / sizeof((a)[0])) // Size of elements in bytes / size of one element in bytes = Number of elements

static inline bool array_contains(const uint32_t* list, size_t count, uint32_t id) {
	for (size_t i = 0; i < count; i++) {
		if (id == list[i]) {
			return true;
		}
	}

	return false;
}