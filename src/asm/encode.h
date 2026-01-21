#pragma once

#include <stdint.h>

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

} AsmReg;