#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef enum {
	STORY_REACHED_OPEN_WORLD = 102, // 0 in intro, 1 after leaving the graveyard
} StoryFlag;

bool story_reached(uint32_t story_flag);