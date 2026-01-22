#pragma once

#include <stdint.h>

#include "spec.h"

typedef struct
{
	const AsmReg *base;
	const AsmReg *index;
	uint8_t scale;
	int64_t disp;
} AsmMemArg;

typedef enum : uint8_t
{
	ASM_ARG_NON,
	ASM_ARG_REG,
	ASM_ARG_IMM,
	ASM_ARG_MEM,
} AsmArgType;

typedef struct
{
	AsmArgType type;
	union {
		const AsmReg *reg;
		int64_t imm;
		AsmMemArg mem;
	};
} AsmArg;

typedef struct
{
	char mnem[MNEM_MAX];
	AsmArg args[ASM_ARG_MAX];
	uint8_t n_args;
} AsmIns;

const AsmMnem *FindMnem(const char *name);
const AsmOpc *FindOpc(const AsmMnem *mnem, const AsmIns *ins);

void EncodeIns(const AsmIns *ins);

bool OpcMatchProf(const AsmOpc *opc, const AsmIns *ins);