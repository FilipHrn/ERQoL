#pragma once

// Event flags used by the mod. 66xxx is a saved block
// Game seems to use multiples of 10, so 9 are free
typedef enum {
	MOD_FLAG_START_RUNES = 66899, // Tells whether a character has already received the start runes
} ModFlag;