#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "core/log.h"
#include "game/game.h"
#include "game/world_chr.h"
#include "features/unlock.h"
#include "features/runes.h"
#include "core/config.h"
#include "core/mod.h"

static DWORD WINAPI MainThread(LPVOID param) {
    HMODULE module = param;

    log_init(module);

    log_msg("Loading mod... Version: %s", MOD_VERSION);
    Config config = config_load(module);

    if (!game_init()) {
        log_msg("Addresses not found, mod disabled");
        return 0;
    }

    log_msg("Success! Mod loaded");
    log_msg("Module base: %p", (void*)g_game.base);

    while (1) {
        if (world_just_loaded()) {
            log_msg("World loaded");

            if (config.unlock) 
                unlock_all();

            if (config.start_runes) 
                runes_give_start(config.start_runes_amount);
        }

        Sleep(500);
    }
    
    return 0;
}

BOOL WINAPI DllMain(HINSTANCE hinst, DWORD reason, LPVOID reserved)
{
    (void)reserved;

    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hinst); // we don't need thread attach/detach calls

        HANDLE thread = CreateThread(NULL, 0, MainThread, hinst, 0, NULL);
        if (thread != NULL) {
            CloseHandle(thread); // the thread keeps running; we just don't need its handle
        }
    }

    return TRUE;
}
