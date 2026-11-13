#pragma once

#include <stdint.h>
#include <stdbool.h>

// GameAreaParam.defeatBossFlagId, whether a boss is dead or not
typedef enum {
	BOSS_MOHG = 12050800,
	BOSS_MALIKETH = 13000800,
	BOSS_RADAHN = 1252380800,
} BossFlag;

bool boss_is_defeated(uint32_t boss_flag);
