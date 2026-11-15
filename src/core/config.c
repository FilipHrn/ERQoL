#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "config.h"
#include "log.h"
#include "path.h"
#include "mod.h"

static bool read_bool(const char* path, const char* section, const char* key, bool fallback) {
	char value[16];
	GetPrivateProfileStringA(section, key, "", value, sizeof(value), path);

	if (_stricmp(value, "true") == 0) return true;
	if (_stricmp(value, "false") == 0) return false;

	return fallback;
}

static int read_int(const char* path, const char* section, const char* key, int fallback) {
	return (int)GetPrivateProfileIntA(section, key, fallback, path);
}

Config config_load(void* module) {
	Config config = { 
		.unlock = true,
		.start_runes = true,
		.start_runes_amount = 999999999,
	};

	char path[MAX_PATH];
	if (!path_next_to_module(module, MOD_NAME "_config.ini", path, sizeof(path))) {
		log_msg("config: could not build path");

		return config;
	}

	config.unlock = read_bool(path, "general", "unlock", config.unlock);
	config.start_runes = read_bool(path, "runes", "start_runes", config.start_runes);
	config.start_runes_amount = read_int(path, "runes", "start_runes_amount", config.start_runes_amount);

	if (config.start_runes_amount < 0) 
		config.start_runes_amount = 0;

	if (config.start_runes_amount > 999999999)
		config.start_runes_amount = 999999999;

	log_msg("config: %s", path);
	log_msg("config: unlock = %s", config.unlock ? "true" : "false");
	log_msg("config: start_runes = %s", config.start_runes ? "true" : "false");
	log_msg("config: start_runes_amount = %d", config.start_runes_amount);

	return config;
}