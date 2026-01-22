#include "spec.h"

const AsmMnem MNEMS[] = {
	{"add", 0, 6},
};
const uint16_t NUM_MNEMS = sizeof(MNEMS) / sizeof(*MNEMS);

const AsmOpc OPCODES[] = {
	{{0x00}, {{ASM_PRM_RM_GEN_OR_MEM, ASM_PRM_BYTE}, {ASM_PRM_GREG, ASM_PRM_BYTE}}},
	{{0x01}, {{ASM_PRM_RM_GEN_OR_MEM, ASM_PRM_VARI}, {ASM_PRM_GREG, ASM_PRM_VARI}}},
	{{0x02}, {{ASM_PRM_GREG, ASM_PRM_BYTE}, {ASM_PRM_RM_GEN_OR_MEM, ASM_PRM_BYTE}}},
	{{0x03}, {{ASM_PRM_GREG, ASM_PRM_VARI}, {ASM_PRM_RM_GEN_OR_MEM, ASM_PRM_VARI}}},
	{{0x04}, {{ASM_PRM_ACCUM, ASM_PRM_BYTE}, {ASM_PRM_IMM, ASM_PRM_BYTE}}},
	{{0x05}, {{ASM_PRM_ACCUM, ASM_PRM_WORD}, {ASM_PRM_IMM, ASM_PRM_WORD}}},
};
const uint16_t NUM_OPCODES = sizeof(OPCODES) / sizeof(*OPCODES);

const AsmReg REGS[] = {
	{"al", 0x00, ASM_REG_BYTE},
	{"cl", 0x01, ASM_REG_BYTE},
	{"dl", 0x02, ASM_REG_BYTE},
	{"bl", 0x03, ASM_REG_BYTE},
	{"ah", 0x04, ASM_REG_BYTE},
	{"ch", 0x05, ASM_REG_BYTE},
	{"dh", 0x06, ASM_REG_BYTE},
	{"bh", 0x07, ASM_REG_BYTE},

	{"ax", 0x00, ASM_REG_WORD},
	{"cx", 0x01, ASM_REG_WORD},
	{"dx", 0x02, ASM_REG_WORD},
	{"bx", 0x03, ASM_REG_WORD},
	{"sp", 0x04, ASM_REG_WORD},
	{"bp", 0x05, ASM_REG_WORD},
	{"si", 0x06, ASM_REG_WORD},
	{"di", 0x07, ASM_REG_WORD},

	{"es", 0x00, ASM_REG_SEGM},
	{"cs", 0x01, ASM_REG_SEGM},
	{"ss", 0x02, ASM_REG_SEGM},
	{"dd", 0x03, ASM_REG_SEGM},
	{"fs", 0x04, ASM_REG_SEGM},
	{"gs", 0x05, ASM_REG_SEGM},

};
const uint8_t NUM_REGS = sizeof(REGS) / sizeof(*REGS);