#include "story.h"
#include "event_flag.h"

bool story_reached(uint32_t story_flag) {
	return event_flag_get(story_flag);
}