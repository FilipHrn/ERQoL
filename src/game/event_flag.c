#include "event_flag.h"
#include "game.h"
#include "core/mem.h"
#include "core/log.h"

typedef void (*SetEventFlagFn)(EventFlagMan* manager, uint32_t* flag_id, uint8_t state);

EventFlagMan* event_flag_man(void) {
    return mem_read_ptr(g_game.event_flag_man);
}

void event_flag_set(uint32_t flag_id) {
    EventFlagMan* manager = event_flag_man();
    if (manager == NULL) {
        log_msg("EventFlagMan not loaded");
        return;
    }

    SetEventFlagFn set_flag = (SetEventFlagFn)g_game.set_event_flag;
    set_flag(manager, &flag_id, 1);
}
