#include "parse.h"
#include "direc.h"
#include "token.h"
#include <ctype.h>
#include <stdint.h>
#include <string.h>

void HandleDirec(AsmBlock *this)
{
	TokStrmNext(&this->strm);

	for (uint8_t i = 0; i != num_directives; ++i)
	{
		if (!strcmp(this->strm.tk, directives[i].mnem))
		{
			//
		}
	}
}

void PrsLine(AsmBlock *this)
{
	printf("%s\t", this->strm.tk);

	if (*this->strm.tk == '.')
	{
		HandleDirec(this);
	}

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
