#include "boss.h"
#include "event_flag.h"

bool boss_is_defeated(uint32_t boss_flag) {
	return event_flag_get(boss_flag);
}