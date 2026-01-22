#include "direc.h"
#include "asm/parse.h"
#include "parse.h"
#include "token.h"

void DirPutBytes(AsmBlock *this, int8_t m)
{
	int64_t v = PrsLit(this);
	PutBytes(this, &v, m);
}

void PutAscii(AsmBlock *this, int8_t m)
{
	this->strm.C = fgetc(this->strm.f);
	while (this->strm.C != '"')
	{
		++this->offs;
		if (this->pass == ASM_PASS_WRIT)
		{
			fputc(this->strm.C, this->out);
		}
		this->strm.C = fgetc(this->strm.f);
	}
	this->strm.C = fgetc(this->strm.f);
	TokStrmNext(&this->strm);
	if (m)
	{
		++this->offs;
		if (this->pass == ASM_PASS_WRIT)
		{
			fputc(0, this->out);
		}
	}
}

const AsmDirec directives[] = {
	{"byte", DirPutBytes, 1},
	{"word", DirPutBytes, 2},
	{"dword", DirPutBytes, 4},
	{"qword", DirPutBytes, 8},
	{"ascii", PutAscii, 0},
	{"asciz", PutAscii, 1},
};

const uint8_t num_directives = sizeof(directives) / sizeof(*directives);