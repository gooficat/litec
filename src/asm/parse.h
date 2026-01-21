#pragma once

#include "token.h"
#include <stdint.h>

typedef struct
{
	TokStrm strm;
	FILE *out;
	uint64_t offs;
} AsmBlock;

void Assemble(const char *in_path);

int64_t PrsLit(AsmBlock *this);

void PrsFile(AsmBlock *this);
