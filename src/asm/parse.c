#include "parse.h"
#include "token.h"
#include <ctype.h>

void PrsFile(AsmBlock *this)
{
	this->offs = 0;

	TokStrmNext(&this->strm);
	while (*this->strm.tk)
	{
		puts(this->strm.tk);

		// test
		if (isdigit(*this->strm.tk))
		{
			int64_t v = PrsLit(this);
			printf("'%lld'\n", v);
		}

		TokStrmNext(&this->strm);
	}
}

void Assemble(const char *in_path)
{
	AsmBlock block;

	TokStrmInit(&block.strm, in_path);

	block.pass = ASM_PASS_LABL;

	PrsFile(&block);
}