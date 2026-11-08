#pragma once
#include <stdint.h>
#include <stddef.h>

typedef struct {
    uint8_t _unknown0[0x28]; // +0x00
    uint8_t* flags; // +0x28
} EventFlagMan;

_Static_assert(offsetof(EventFlagMan, flags) == 0x28, "flags must be at +0x28");

EventFlagMan* event_flag_man(void);
void event_flag_set(uint32_t flag_id);
