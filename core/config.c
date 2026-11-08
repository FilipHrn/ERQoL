#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "config.h"
#include "log.h"
#include "path.h"

static bool read_bool(const char* path, const char* section, const char* key, bool fallback) {
	char value[16];
	GetPrivateProfileStringA(section, key, "", value, sizeof(value), path);

	if (_stricmp(value, "true") == 0) return true;
	if (_stricmp(value, "false") == 0) return false;

	return fallback;
}

Config config_load(void* module) {
	Config config = { .auto_unlock = true };

	char path[MAX_PATH];
	if (!path_next_to_module(module, "mod_config.ini", path, sizeof(path))) {
		log_msg("config: could not build path");

		return config;
	}

	config.auto_unlock = read_bool(path, "general", "auto_unlock", config.auto_unlock);

	log_msg("config: %s", path);
	log_msg("config: auto_unlock = %s", config.auto_unlock ? "true" : "false");

	return config;
}