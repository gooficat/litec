#pragma once

#include "parse.h"
#include <stdint.h>

typedef struct
{
	const char *mnem;
	void (*fn)(AsmBlock *this, int8_t m);
	int8_t m;
} AsmDirec;

extern const AsmDirec directives[];
extern const uint8_t num_directives;