#include "runes.h"
#include "game/game_data.h"
#include "core/log.h"

#define RUNES_MAX 999999999

void runes_add(int amount) {
    GameDataMan* gdm = game_data_man();
    if (gdm == NULL || gdm->player == NULL) {
        log_msg("Player data not loaded");
        return;
    }

    PlayerGameData* player = gdm->player;

    int before = player->runes;
    int after = (amount > RUNES_MAX - before) ? RUNES_MAX : before + amount;

    player->runes = after;

    log_msg("Runes %d -> %d", before, after);
}