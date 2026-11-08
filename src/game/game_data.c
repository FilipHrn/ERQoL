#include "game_data.h"
#include "game.h"
#include "core/mem.h"

GameDataMan* game_data_man(void) {
	return mem_read_ptr(g_game.game_data_man);
}