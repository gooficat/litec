#include "parse.h"
#include "token.h"

void PrsFile(AsmBlock *this)
{
	this->offs = 0;

	TokStrmNext(&this->strm);
	while (*this->strm.tk)
	{
		TokStrmNext(&this->strm);
		puts(this->strm.tk);
	}
}

void Assemble(const char *in_path)
{
	AsmBlock block;

	TokStrmInit(&block.strm, in_path);
}