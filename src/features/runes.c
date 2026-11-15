#include <stdbool.h>

#include "runes.h"
#include "core/log.h"
#include "game/game_data.h"
#include "game/mod_flag.h"
#include "game/event_flag.h"
#include "game/story.h"

#define RUNES_MAX 999999999

static bool runes_add(int amount) {
	GameDataMan* gdm = game_data_man();
	if (gdm == NULL || gdm->player == NULL) {
		log_msg("Player data not loaded");
		return false;
	}

	PlayerGameData* player = gdm->player;

	int before = player->runes;
	int after = (amount > RUNES_MAX - before) ? RUNES_MAX : before + amount;

	player->runes = after;

	log_msg("Runes %d -> %d", before, after);

	return true;
}

void runes_give_start(int amount) {
	if (!story_reached(STORY_REACHED_OPEN_WORLD)) // Still in tutorial
		return;

	if (amount <= 0 || event_flag_get(MOD_FLAG_START_RUNES)) // Runes already given
		return;

	if (runes_add(amount))
		event_flag_set(MOD_FLAG_START_RUNES);
}