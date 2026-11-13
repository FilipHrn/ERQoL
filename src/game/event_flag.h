#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef struct EventFlagMan EventFlagMan;

EventFlagMan* event_flag_man(void);

void event_flag_set(uint32_t flag_id);
bool event_flag_get(uint32_t flag_id);