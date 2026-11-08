ERQoL - Elden Ring quality-of-life mod
https://github.com/FilipHrn/ERQoL

WHAT IT DOES
  Unlocks all Sites of Grace and map pieces automatically when you load a save.
  No map popups, nothing to press.
  Skipped on purpose: Ashen Capital graces and Fractured Marika.

REQUIREMENTS
  - Elden Ring 2.7.2.0 (other versions may work)
  - Mod Engine 2
  - Offline only. Do not use online with Easy Anti-Cheat.

INSTALL
  1. Put ERQoL.dll and ERQoL_config.ini in the same folder,
     for example an "ERQoL" folder next to config_eldenring.toml.
  2. Add the DLL to external_dlls in config_eldenring.toml:

       external_dlls = [
           "ERQoL/ERQoL.dll",
       ]

  3. Start the game with Mod Engine 2 and load a save.

  The unlocks are written to your save file. Back up your save first.

SETTINGS (ERQoL_config.ini)
  auto_unlock = true    unlock automatically when a save is loaded (default)
  auto_unlock = false   hotkeys instead: (popups will be present as if you picked up a map manually)
                          F5 = +10,000 runes
                          F8 = unlock all graces and map pieces

TROUBLESHOOTING
  ERQoL_log.log is created next to the DLL every time the game starts.
  If nothing happens, check it. "AOB not found" means the game version is
  not supported yet. Include the log when reporting a bug.

CREDITS
  Hexinton's Elden Ring all-in-one cheat table, Mod Engine 2.
