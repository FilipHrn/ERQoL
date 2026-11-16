#pragma once
#include <stdbool.h>

typedef struct {
	bool unlock;
	bool start_runes;
	int start_runes_amount;
	bool dungeon_warp;
} Config;

Config config_load(void* module);