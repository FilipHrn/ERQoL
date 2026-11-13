#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "game.h"
#include "core/mem.h"
#include "core/log.h"

// Patterns from Hexinton CT v2.93, verified on 2.7.2.0
#define AOB_EVENTFLAGMAN "48 8B 3D ?? ?? ?? ?? 48 85 FF ?? ?? 32 C0 E9"
#define AOB_PARAM        "48 8B 0D ?? ?? ?? ?? 48 85 C9 0F 84 ?? ?? ?? ?? 45 33 C0 BA 8E 00 00 00"
#define AOB_GAMEDATAMAN  "48 8B 05 ?? ?? ?? ?? 48 85 C0 74 05 48 8B 40 58 C3 C3"
#define AOB_WORLDCHRMAN  "48 8B 05 ?? ?? ?? ?? 48 85 C0 74 0F 48 39 88"
#define AOB_SETEVENTFLAG "48 89 5C 24 08 48 89 74 24 18 57 48 83 EC 30 48 8B DA 41 0F B6 F8 8B 12 48 8B F1 85 D2 0F 84 ?? ?? ?? ??"
#define AOB_GETEVENTFLAG "44 8B 41 1C 44 8B DA 33 D2 41 8B C3" // Not from CT but, derived from SetEventFlag

GameAddresses g_game;

static uintptr_t find_static(const char* name, const char* pattern) {
	uintptr_t address = mem_resolve_rip(mem_scan(g_game.base, pattern), 3, 7);

	if (address == 0) 
		log_msg("AOB not found: %s", name);

	return address;
}

static uintptr_t find_function(const char* name, const char* pattern) {
	uintptr_t address = mem_scan(g_game.base, pattern);

	if (address == 0) 
		log_msg("AOB not found: %s", name);

	return address;
}

int game_init(void) {
	g_game.base = (uintptr_t)GetModuleHandleA(NULL);

	g_game.event_flag_man = find_static("EventFlagMan", AOB_EVENTFLAGMAN);
	g_game.param_repo = find_static("PARAM", AOB_PARAM);
	g_game.game_data_man = find_static("GameDataMan", AOB_GAMEDATAMAN);
	g_game.world_chr_man = find_static("WorldChrMan", AOB_WORLDCHRMAN);

	g_game.set_event_flag = find_function("SetEventFlag", AOB_SETEVENTFLAG);
	g_game.get_event_flag = find_function("GetEventFlag", AOB_GETEVENTFLAG);

	return g_game.event_flag_man != 0
		&& g_game.param_repo != 0
		&& g_game.game_data_man != 0
		&& g_game.world_chr_man != 0
		&& g_game.set_event_flag != 0
		&& g_game.get_event_flag != 0;
}