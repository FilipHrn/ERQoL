#include "warp.h"
#include "core/log.h"
#include "game/param.h"

static int warp_enable_in_dungeons_and_tunnels(void) {
	ParamTable* table = param_get_table(PARAM_MAPDEFAULTINFO);
	if (table == NULL) {
		log_msg("param %d not ready", PARAM_MAPDEFAULTINFO);
		return 0;
	}

	int count = 0;

	for (uint16_t i = 0; i < table->row_count; i++) {
		MapDefaultInfoData* row = param_row_data_mutable(table, i);

		if (row->enable_fast_travel_event_flag_id != 0) {
			row->enable_fast_travel_event_flag_id = 0;

			count++;
		}
	}

	return count;
}

void warp_unblock(void) {
	int warps_unblocked = warp_enable_in_dungeons_and_tunnels(); // 0 = already unblocked. Needs to unblock only once per session

	if (warps_unblocked > 0)
		log_msg("Dungeon warp: %d maps unblocked", warps_unblocked);
}