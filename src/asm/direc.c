#include "direc.h"
#include "parse.h"
#include "token.h"

void PutBytes(AsmBlock *this, int8_t m)
{
	TokStrmNext(&this->strm);
}

void PutAscii(AsmBlock *this, int8_t m)
{
	//
}

const AsmDirec directives[] = {
	{"byte", PutBytes, 1},
	{"word", PutBytes, 2},
	{"dword", PutBytes, 4},
	{"qword", PutBytes, 8},
	{"ascii", PutAscii, 0},
	{"asciz", PutAscii, 1},
};

const uint8_t num_directives = sizeof(directives) / sizeof(*directives);