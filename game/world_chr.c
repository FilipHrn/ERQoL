#include "world_chr.h"
#include "game.h"
#include "core/mem.h"

WorldChrMan* world_chr_man(void) {
	return mem_read_ptr(g_game.world_chr_man);
}