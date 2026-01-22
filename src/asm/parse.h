#pragma once

#include "token.h"
#include <stdint.h>

typedef enum : uint8_t
{
	ASM_PASS_LABL,
	ASM_PASS_ALGN,
	ASM_PASS_WRIT,
	ASM_PASS_DONE,
} AsmPass;

typedef struct
{
	TokStrm strm;
	FILE *out;
	uint64_t offs;
	AsmPass pass;
} AsmBlock;

void Assemble(const char *in_path, const char *out_path);

int64_t PrsLit(AsmBlock *this);

void PrsFile(AsmBlock *this);

void PutBytes(AsmBlock *this, const void *data, size_t n);