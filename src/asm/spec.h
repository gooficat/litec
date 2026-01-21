#pragma once

#include <stdint.h>

#define MNEM_MAX 12

#define ASM_ARG_MAX 4

typedef enum : uint8_t
{
	ASM_REG_BYTE,
	ASM_REG_WORD,
	ASM_REG_DWOR,
	ASM_REG_QWOR,
} AsmRegType;

typedef struct
{
	const char *name;
	uint8_t code;
	AsmRegType type;
} AsmReg;