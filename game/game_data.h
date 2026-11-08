#pragma once
#include <stdint.h>
#include <stddef.h>

typedef struct {
	uint8_t _unknown0[0x6C];    // +0x00
	int32_t runes;              // +0x6C
} PlayerGameData;

typedef struct {
	uint8_t _unknown0[0x08];    // +0x00
	PlayerGameData* player;     // +0x08
} GameDataMan;

_Static_assert(offsetof(PlayerGameData, runes) == 0x6C, "runes must be at +0x6C");
_Static_assert(offsetof(GameDataMan, player) == 0x08, "player must be at +0x08");

GameDataMan* game_data_man(void);