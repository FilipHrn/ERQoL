# ER QoL mod

A small quality-of-life DLL mod for Elden Ring, written in C and loaded with Mod Engine 2.

## Features

- **Unlock all Sites of Grace and map pieces** automatically when a save is loaded.
  No map popups, nothing to press.
- **Start runes** (on by default): give a configurable amount of runes once per character.
  They arrive on the first loading screen after you leave the starting area, so the scripted death
  at the start can't take them.

Graces that are not unlocked on purpose:
- **Boss arena graces** (Godrick, Margit, Morgott, Rennala, Radahn, Malenia, Messmer, ...).
  They appear as usual once you beat the boss.
- **Leyndell** follows the story: Royal Capital graces before Maliketh is defeated,
  Ashen Capital graces after.

## Compatibility

- Tested on Elden Ring **2.7.2.0** (Steam).
- Addresses are found with byte-pattern (AOB) scans, so the mod may keep working after game updates.
  If a pattern is not found, the mod disables itself and writes `AOB not found` to the log.
- **Offline only.** Do not use it online with Easy Anti-Cheat.

## Installation

1. Install [Mod Engine 2](https://github.com/soulsmods/ModEngine2).
2. Download the latest zip from [Releases](https://github.com/FilipHrn/ERQoL/releases)
   and extract `ERQoL.dll` and `ERQoL_config.ini` into the same folder, for example an `ERQoL` folder
   next to `config_eldenring.toml`.
3. Add the DLL to `external_dlls` in `config_eldenring.toml` (the path is relative to the toml file):
   ```toml
   [modengine]
   external_dlls = [
       "ERQoL/ERQoL.dll",
   ]
   ```
4. Start the game with Mod Engine 2 and load a save.

Unlocked graces, map pieces and start runes are written to your save file. Back up your save before trying the mod.

## Configuration

`ERQoL_config.ini` (next to the DLL):

```ini
[general]
; true = unlock maps and graces when a save is loaded
unlock = true

[runes]
; true = give runes once per character, after leaving starting area and going through first loading screen
start_runes = true
; amount, 0 - 999999999
start_runes_amount = 999999999
```

Missing keys use the defaults: `unlock = true`, `start_runes = true`, `start_runes_amount = 999999999`.

Start runes are **not** given the moment you walk out of the Stranded Graveyard. They arrive on the
first loading screen after that (teleport, death or reload). Each character gets them once.
Characters that are already further in the game get them on their next loading screen.

## Known issues

- Right after unlocking, graces in the world may still say "Touch grace" until the next loading screen.
- Underground and DLC graces are unlocked (they show in the travel menu), but the map only lets you
  switch to the underground / Realm of Shadow map after you have been there once.

## Log

`ERQoL_log.log` is created next to the DLL and starts fresh on every launch.
Include it when reporting a bug.

## Changelog

### 0.2.0 (unreleased)

- Added: start runes (`[runes]` section in the config, on by default).
- Fixed: boss arena graces are no longer unlocked before the boss is defeated.
- Fixed: Leyndell switches from Royal Capital to Ashen Capital graces after Maliketh, like the base game.
- Changed: config key `auto_unlock` is now `unlock`.
- Removed: hotkey mode (F5 runes, F8 unlock).
- Changed: release builds no longer log every skipped grace.

Saves already unlocked with 0.1.0 keep the graces that version set.

### 0.1.0

- First release: unlock all graces and map pieces on load, optional hotkey mode.

## Building from source

- Visual Studio 2026 with the **Desktop development with C++** workload (MSVC v145).
- Open `ERQoL.slnx`, select **Release | x64**, and build.
- Output: `build\Release\ERQoL.dll` and `build\Release\ERQoL_config.ini`.

Project layout:

```
src/
  main.c       entry point and main loop
  core/        log, config, paths, memory scanning
  game/        structs, getters and flag names for game memory
  features/    unlock, runes
```

## Credits

- [Hexinton's Elden Ring all-in-one cheat table (v2.93)](https://github.com/Hexinton/eldenringcheatengine) for the AOB patterns and memory layouts.
- [Elden Ring Event Flag Reference](https://soulsmods.github.io/elden-ring-eventparam/) for event flag ranges.
- [Mod Engine 2](https://github.com/soulsmods/ModEngine2) for loading the DLL.

## License

MIT, see [LICENSE](LICENSE).
