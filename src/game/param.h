#pragma once
#include <stdint.h>
#include <stddef.h>

#define PARAM_BONFIRE 43 // BonfireWarpParam
#define PARAM_MAPPIECE 88 // WorldMapPieceParam

typedef struct {
	uint32_t _flags; // +0x00
	uint32_t event_flag_id; // +0x04
} BonfireWarpData;

typedef struct {
	uint32_t _flags;                      // +0x00
	uint32_t open_event_flag_id;          // +0x04
	float open_travel_area_left;          // +0x08
	float open_travel_area_right;         // +0x0C
	float open_travel_area_top;           // +0x10
	float open_travel_area_bottom;        // +0x14
	uint32_t acquisition_event_flag_id;   // +0x18
} WorldMapPieceData;

typedef struct {
	uint32_t id;               // +0x00
	uint32_t _unknown0;        // +0x04
	uint32_t data_offset;      // +0x08
	uint8_t _unknown1[0x0C];   // +0x0C
} ParamRow;

typedef struct {
	uint8_t _unknown0[0x0A];   // +0x00
	uint16_t row_count;        // +0x0A
	uint8_t _unknown1[0x34];   // +0x0C
} ParamTable;

typedef struct {
	uint8_t _unknown0[0x80]; // +0x00
	ParamTable* table; // +0x80
} ParamHolder;

typedef struct {
	uint8_t _unknown0[0x80]; // +0x00
	ParamHolder* holder; // +0x80
} ParamSlot;

typedef struct {
	ParamSlot* slot;            // +0x00
	uint8_t _unknown0[0x40];    // +0x08
} ParamEntry;

typedef struct {
	uint8_t _unknown0[0x88];    // +0x00
	ParamEntry entries[];       // +0x88
} ParamRepository;

_Static_assert(offsetof(WorldMapPieceData, acquisition_event_flag_id) == 0x18, "acquisition flag must be at +0x18");

_Static_assert(sizeof(ParamRow) == 0x18, "ParamRow must be 0x18 bytes");
_Static_assert(sizeof(ParamTable) == 0x40, "ParamTable header must be 0x40 bytes");
_Static_assert(offsetof(ParamHolder, table) == 0x80, "table must be at +0x80");
_Static_assert(offsetof(ParamSlot, holder) == 0x80, "holder must be at +0x80");
_Static_assert(sizeof(ParamEntry) == 0x48, "ParamEntry must be 0x48 bytes");
_Static_assert(offsetof(ParamRepository, entries) == 0x88, "entries must start at +0x88");

const void* param_row_data(ParamTable* table, uint16_t index);

ParamTable* param_get_table(int index);
ParamRepository* param_repo(void);