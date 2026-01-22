#include "parse.h"
#include "token.h"
#include <ctype.h>

void PrsLine(AsmBlock *this)
{
	printf("%s\t", this->strm.tk);

	TokStrmNext(&this->strm);
}

void PrsFile(AsmBlock *this)
{
	this->offs = 0;

	TokStrmNext(&this->strm);
	while (*this->strm.tk)
	{
		PrsLine(this);
	}
}

void Assemble(const char *in_path)
{
	AsmBlock block;

	TokStrmInit(&block.strm, in_path);

	block.pass = ASM_PASS_LABL;

	PrsFile(&block);
}

void PutBytes(AsmBlock *this, const void *data, size_t n)
{
	this->offs += n;
	if (this->pass == ASM_PASS_WRIT)
	{
		fwrite(data, 1, n, this->out);
	}
}
