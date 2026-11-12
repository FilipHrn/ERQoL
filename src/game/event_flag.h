#pragma once
#include <stdint.h>

typedef struct EventFlagMan EventFlagMan;

EventFlagMan* event_flag_man(void);
void event_flag_set(uint32_t flag_id);
