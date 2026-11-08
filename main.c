#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "core/log.h"
#include "game/game.h"
#include "features/unlock.h"
#include "features/runes.h"

static DWORD WINAPI MainThread(LPVOID param) {
	(void)param;

    if (!game_init()) {
        log_msg("Addresses not found, mod disabled");
        return 0;
    }

    log_msg("Success! Mod loaded");
    log_msg("Module base: %p", (void*)g_game.base);

    while (1) {
        if (GetAsyncKeyState(VK_F5) & 1) runes_add(10000);

        if (GetAsyncKeyState(VK_F8) & 1) unlock_all();

        Sleep(50);
    }

    return 0;
}

BOOL WINAPI DllMain(HINSTANCE hinst, DWORD reason, LPVOID reserved)
{
    (void)reserved;

    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hinst); // we don't need thread attach/detach calls

        HANDLE thread = CreateThread(NULL, 0, MainThread, NULL, 0, NULL);
        if (thread != NULL) {
            CloseHandle(thread); // the thread keeps running; we just don't need its handle
        }
    }

    return TRUE;
}
