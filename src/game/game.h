#pragma once
#include <stdint.h>

typedef struct {
	uintptr_t base; // Start of eldenring.exe
	uintptr_t event_flag_man; // Event flag manager
	uintptr_t set_event_flag; // Set-flag function
	uintptr_t param_repo; // Param repository pointer
	uintptr_t game_data_man; // Game data manager
	uintptr_t world_chr_man; // Characters in the world
} GameAddresses;

extern GameAddresses g_game;

int game_init(void);