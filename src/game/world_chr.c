#include "world_chr.h"
#include "game.h"
#include "core/mem.h"

WorldChrMan* world_chr_man(void) {
	return mem_read_ptr(g_game.world_chr_man);
}

bool world_just_loaded(void) {
	static bool was_in_world = false;

	WorldChrMan* wcm = world_chr_man();
	bool in_world = wcm != NULL && wcm->main_player != NULL;

	bool loaded = in_world && !was_in_world;
	was_in_world = in_world;

	return loaded;
}