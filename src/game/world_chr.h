#pragma once
#include <stdint.h>
#include <stddef.h>

typedef struct {
	uint8_t _unknown0[0x1E508]; // +0x00
	void* main_player; // +0x1E508
} WorldChrMan;

_Static_assert(offsetof(WorldChrMan, main_player) == 0x1E508, "main_player must be at +0x1E508");

WorldChrMan* world_chr_man(void);