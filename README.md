# ER QoL mod

A small quality-of-life DLL mod for Elden Ring, written in C and loaded with Mod Engine 2.

## Features

- **Unlock all Sites of Grace and map pieces** automatically when a save is loaded.
  No map popups, nothing to press.
- **Hotkey mode** (optional, see [Configuration](#configuration)):
  - `F5` adds 10,000 runes
  - `F8` unlocks all graces and map pieces

Graces that are skipped on purpose:
- Ashen Capital graces (they only make sense after the story changes Leyndell)
- Fractured Marika (final boss arena)

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

Unlocked graces and map pieces are written to your save file. Back up your save before trying the mod.

## Configuration

`ERQoL_config.ini` (next to the DLL):

```ini
[general]
; true  = unlock automatically when a save is loaded, hotkeys off
; false = hotkeys on: F5 runes, F8 unlock
auto_unlock = true
```

If the file is missing, the mod uses the default (`auto_unlock = true`).

## Log

`ERQoL_log.log` is created next to the DLL and starts fresh on every launch.
Include it when reporting a bug.

## Building from source

- Visual Studio 2026 with the **Desktop development with C++** workload (MSVC v145).
- Open `ERQoL.slnx`, select **Release | x64**, and build.
- Output: `build\Release\ERQoL.dll` and `build\Release\ERQoL_config.ini`.

Project layout:

```
src/
  main.c       entry point and main loop
  core/        log, config, paths, memory scanning
  game/        structs and getters for game memory
  features/    unlock, runes
```

## Credits

- [Hexinton's Elden Ring all-in-one cheat table (v2.93)](https://github.com/Hexinton/eldenringcheatengine) for the AOB patterns and memory layouts.
- [Mod Engine 2](https://github.com/soulsmods/ModEngine2) for loading the DLL.

## License

MIT, see [LICENSE](LICENSE).