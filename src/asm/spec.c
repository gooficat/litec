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
