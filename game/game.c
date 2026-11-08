#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "game.h"

// ER 2.7.2.0, found by hand
#define OFFSET_EVENTFLAGMAN 0x3D6F4D8
#define OFFSET_SETEVENTFLAG 0x5D3410
#define OFFSET_PARAM 0x3D88F78
#define OFFSET_GAMEDATAMAN 0x3D818C8

GameAddresses g_game;

void game_init(void) {
	g_game.base = (uintptr_t)GetModuleHandleA(NULL);
	g_game.event_flag_man = g_game.base + OFFSET_EVENTFLAGMAN;
	g_game.set_event_flag = g_game.base + OFFSET_SETEVENTFLAG;
	g_game.param_repo = g_game.base + OFFSET_PARAM;
	g_game.game_data_man = g_game.base + OFFSET_GAMEDATAMAN;
}