#include "encode.h"
#include "spec.h"
#include <string.h>

const AsmMnem *FindMnem(const char *name)
{
	for (uint8_t i = 0; i != NUM_MNEMS; ++i)
	{
		if (!strcmp(name, MNEMS[i].name))
		{
			return &MNEMS[i];
		}
	}
	return NULL;
}

bool ArgMatchProf(const AsmPrm *prm, const AsmArg *arg)
{
	switch (arg->type)
	{
	case ASM_ARG_IMM:
		if (prm->type == ASM_PRM_IMM)
		{
			// if (prm->size == ASM_PRM_BYTE && arg->imm )
		}
		else
		{
			return false;
		}
	case ASM_ARG_REG:
	case ASM_ARG_MEM:
	case ASM_ARG_NON:
		return prm->type == ASM_PRM_NON;
	}
}

bool OpcMatchProf(const AsmOpc *opc, const AsmIns *ins)
{
	for (uint8_t i = 0; i != ASM_ARG_MAX; ++i)
	{
		if (!ArgMatchProf(&opc->params[i], &ins->args[i]))
		{
			return false;
		}
	}
	return true;
}

const AsmOpc *FindOpc(const AsmMnem *mnem, const AsmIns *ins)
{
	for (uint16_t i = mnem->idx; i != mnem->idx + mnem->num; ++i)
	{
		if (OpcMatchProf(&OPCODES[i], ins))
		{
			return &OPCODES[i];
		}
	}
	return NULL;
}

void EncodeIns(const AsmIns *ins)
{
	const AsmOpc *opc = FindOpc(FindMnem(ins->mnem), ins);

	//
}