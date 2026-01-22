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
			TokStrmNext(&this->strm);
			directives[i].fn(this, directives[i].m);
			break;
		}
	}
}

AsmLabl *FindLabl(AsmBlock *this)
{
	for (size_t i = 0; i != this->labels.size; ++i)
	{
		if (!strcmp(this->strm.tk, this->labels.data[i].name))
		{
			return &this->labels.data[i];
		}
	}
	return NULL;
}

void HandleLabl(AsmBlock *this)
{
	if (this->pass == ASM_PASS_LABL)
	{
		AddLabl(this, 0);
	}
	else if (this->pass == ASM_PASS_ALGN)
	{
		AsmLabl *lb = FindLabl(this);
		if (lb->offs != this->offs)
		{
			this->next_pass = ASM_PASS_ALGN;
			lb->offs = this->offs;
		}
	}
	this->strm.C = fgetc(this->strm.f);
	TokStrmNext(&this->strm);
}

void AddLabl(AsmBlock *this, const uint64_t offs)
{
	AsmLabl lb;
	lb.name = _strdup(this->strm.tk);
	lb.offs = offs;

	Push(this->labels, lb);
}

void PrsLine(AsmBlock *this)
{

	if (*this->strm.tk == '.')
	{
		HandleDirec(this);
	}
	else if (this->strm.C == ':')
	{
		HandleLabl(this);
	}
	else if (isalpha(*this->strm.tk))
	{
		HandleIns(this);
	}
	else
	{
		// printf("%s\n", this->strm.tk);
	}
}

void PrsFile(AsmBlock *this)
{
	this->offs = 0;

	TokStrmNext(&this->strm);
	while (*this->strm.tk)
	{
		PrsLine(this);
	}

	this->pass = this->next_pass;
}

void Assemble(const char *in_path, const char *out_path)
{
	AsmBlock block;

	TokStrmInit(&block.strm, in_path);
	fopen_s(&block.out, out_path, "wb");

	InitVec(block.labels);

	block.pass = ASM_PASS_LABL;

	PrsFile(&block);

	for (size_t i = 0; i != block.labels.size; ++i)
	{
		printf("Label %s at %llu\n", block.labels.data[i].name, block.labels.data[i].offs);
	}
}

void PutBytes(AsmBlock *this, const void *data, size_t n)
{
	this->offs += n;
	if (this->pass == ASM_PASS_WRIT)
	{
		fwrite(data, 1, n, this->out);
	}
}
