ERQoL - Elden Ring quality-of-life mod
https://github.com/FilipHrn/ERQoL

WHAT IT DOES
  Unlocks all Sites of Grace and map pieces automatically when you load a save.
  No map popups, nothing to press.
  Not unlocked on purpose:
    - Boss arena graces: they appear as usual once you beat the boss.
    - Leyndell follows the story: Royal Capital graces before Maliketh,
      Ashen Capital graces after.

  Start runes (on by default): given once per character on the first
  loading screen after you leave the starting area (so the scripted death
  at the start can't take them).

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

  Unlocks and start runes are written to your save file. Back up your save first.

SETTINGS (ERQoL_config.ini)
  [general]
  unlock = true                unlock graces and map pieces on load (default)
  unlock = false               don't unlock anything

  [runes]
  start_runes = true               give start runes once per character (default)
  start_runes = false              no start runes
  start_runes_amount = 999999999   how many, 0 - 999999999 (default 999999999)

  Start runes do NOT arrive the moment you walk out of the Stranded Graveyard.
  They arrive on the first loading screen after that (teleport, death or reload).

KNOWN ISSUES
  - Graces may still say "Touch grace" until the next loading screen.
  - The underground and DLC maps can only be selected on the map screen
    after you have visited them once. Their graces are already in the
    travel menu.

TROUBLESHOOTING
  ERQoL_log.log is created next to the DLL every time the game starts.
  If nothing happens, check it. "AOB not found" means the game version is
  not supported yet. Include the log when reporting a bug.

CREDITS
  Hexinton's Elden Ring all-in-one cheat table, Elden Ring Event Flag Reference
  (soulsmods), Mod Engine 2.
