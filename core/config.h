#pragma once
#include <stdbool.h>

typedef struct {
	bool auto_unlock;
} Config;

Config config_load(void* module);