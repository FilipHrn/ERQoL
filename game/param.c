#include "param.h"
#include "game.h"
#include "core/mem.h"

ParamRepository* param_repo(void) {
    return mem_read_ptr(g_game.param_repo);
}

ParamTable* param_get_table(int index) {
    ParamRepository* repo = param_repo();
    if (repo == NULL) return NULL;

    ParamSlot* slot = repo->entries[index].slot;
    if (slot == NULL || slot->holder == NULL) return NULL;

    ParamTable* table = slot->holder->table;
    if (table == NULL || table->row_count == 0 || table->row_count > 2000) return NULL;

    return table;
}

static ParamRow* param_rows(ParamTable* table) {
    return (ParamRow*)(table + 1);
}

const void* param_row_data(ParamTable* table, uint16_t index) {
    ParamRow* rows = param_rows(table);
    return (const uint8_t*)table + rows[index].data_offset;
}