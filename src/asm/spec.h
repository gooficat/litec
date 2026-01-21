#pragma once

#include <stdint.h>

#define MNEM_MAX 12

#define ASM_ARG_MAX 4
#define ASM_OPC_MAX 2

typedef enum : uint8_t
{
	ASM_REG_BYTE,
	ASM_REG_WORD,
} AsmRegType;

typedef struct
{
	const char *name;
	uint8_t code;
	AsmRegType type;
} AsmReg;

typedef enum : uint8_t
{
	ASM_PRM_DIR,		   // direct address, no modrm
	ASM_PRM_RM_GEN_OR_MEM, // rm field general reg or memory
	ASM_PRM_GREG,		   // general register
	ASM_PRM_IMM,		   // immediate value
	ASM_PRM_REL,		   // relative offset, like jmp
	ASM_PRM_RM_MEM_ONLY,   // rm field mem only
	ASM_PRM_MEM,		   // mem offset
	ASM_PRM_SREG,		   // segment in reg field
	ASM_PRM_TAIL_GEN,	   // tail end of opcode encodes a register
	ASM_PRM_ACCUM,		   // fixed accumulator form
} AsmPrmType;
typedef enum : uint8_t
{
	ASM_PRM_BYTE,
	ASM_PRM_WORD,
	ASM_PRM_VARI,
	ASM_PRM_DW_SOFFS,
} AsmPrmSize;

typedef struct
{
	AsmPrmType type;
	AsmPrmSize size;
} AsmPrm;

typedef struct
{
	const char *name;
	uint16_t idx;
	uint8_t num;
} AsmMnem;

typedef struct
{
	uint8_t opcodes[ASM_OPC_MAX];
	AsmPrm params[ASM_ARG_MAX];
} AsmOpc;

extern const AsmMnem MNEMS[];
extern const uint16_t NUM_MNEMS;

extern const AsmOpc OPCODES[];
extern const uint16_t NUM_OPCODES;
