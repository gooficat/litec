#include "asm/parse.h"
#include "encode.h"
#include "parse.h"
#include "spec.h"
#include "token.h"
#include <ctype.h>
#include <string.h>

const AsmReg *FindReg(AsmBlock *this)
{
	for (uint8_t i = 0; i != NUM_REGS; ++i)
	{
		if (!strcmp(this->strm.tk, REGS[i].name))
		{
			return &REGS[i];
		}
	}

	return NULL;
}

AsmMemArg PrsMemArg(AsmBlock *this)
{
	AsmMemArg out;

	if (isdigit(*this->strm.tk))
	{
		out.disp = PrsLit(this);
	}
	else
	{
		out.disp = 0;
	}
	if (*this->strm.tk == '(')
	{
		TokStrmNext(&this->strm);
		if (*this->strm.tk == '%')
		{
			TokStrmNext(&this->strm);
			out.base = FindReg(this);
		}
		else
		{
			out.base = NULL;
		}
		if (*this->strm.tk != ')')
		{
			TokStrmNext(&this->strm);
			if (*this->strm.tk == '%')
			{
				TokStrmNext(&this->strm);
				out.index = FindReg(this);
			}
			else
			{
				out.index = NULL;
			}
			if (*this->strm.tk != ')')
			{
				TokStrmNext(&this->strm);
				out.scale = PrsLit(this);
			}
			else
			{
				out.scale = 0;
			}
		}
		TokStrmNext(&this->strm);
	}

	return out;
}

AsmIns PrsIns(AsmBlock *this)
{
	AsmIns ins;
	strcpy_s(ins.mnem, sizeof(ins.mnem), this->strm.tk);
	ins.n_args = 0;
	if (!TokStrmEol(&this->strm))
	{
		TokStrmNext(&this->strm);

		for (;;)
		{
			AsmArg arg;

			if (this->strm.C == '%')
			{
				arg.type = ASM_ARG_REG;
				TokStrmNext(&this->strm);
				arg.reg = FindReg(this);
				TokStrmNext(&this->strm);
			}
			else if (this->strm.C == '$')
			{
				arg.type = ASM_ARG_IMM;
				TokStrmNext(&this->strm);
				arg.imm = PrsLit(this);
			}
			else
			{
				arg.type = ASM_ARG_MEM;
				arg.mem = PrsMemArg(this);
			}

			ins.args[ins.n_args++] = arg;

			if (*this->strm.tk == ',')
			{
				TokStrmNext(&this->strm);
			}
			else
			{
				break;
			}
		}
	}
	else
	{
		TokStrmNext(&this->strm);
	}
	return ins;
}

void HandleIns(AsmBlock *this)
{
	AsmIns ins = PrsIns(this);
	printf("\n%s %hhu\n", ins.mnem, ins.n_args);
}
