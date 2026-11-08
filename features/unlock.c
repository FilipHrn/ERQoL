#include <stdint.h>

#include "unlock.h"
#include "game/param.h"
#include "game/event_flag.h"
#include "core/log.h"

typedef int (*SkipFn)(uint32_t id);
typedef uint32_t(*FlagFn)(const void* row);

static uint32_t grace_flag(const void* row) {
    const BonfireWarpData* grace = row;
    return grace->event_flag_id;
}

static uint32_t map_flag(const void* row) {
    const WorldMapPieceData* map = row;
    return map->open_event_flag_id;
}

static int skip_grace(uint32_t id) {
	if (id == 200) return 1;                    // row 0: placeholder, not a grace
	if (id >= 71120 && id <= 71125) return 1;   // Ashen Capital (only after the story burns it)
	if (id == 71900) return 1;                  // Fractured Marika (final boss)

	return 0;
}

static int set_flags_from_param(int index, FlagFn get_flag, SkipFn skip) {
    ParamTable* table = param_get_table(index);
    if (table == NULL) { log_msg("param %d not ready", index); return 0; }

    int count = 0;

    for (uint16_t i = 0; i < table->row_count; i++) {
        uint32_t flag_id = get_flag(param_row_data(table, i));

        if (skip != NULL && skip(flag_id)) {
            log_msg("skip flag %u", flag_id);
            continue;
        }

        event_flag_set(flag_id);
        count++;
    }

    return count;
}

void unlock_all(void) {
    int graces = set_flags_from_param(PARAM_BONFIRE, grace_flag, skip_grace);
    int maps = set_flags_from_param(PARAM_MAPPIECE, map_flag, NULL);

    log_msg("Graces set: %d, map pieces set: %d", graces, maps);
}