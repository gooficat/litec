#include "token.h"
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>

void TokStrmInit(TokStrm *this, const char *path)
{
	fopen_s(&this->f, path, "rt");
	this->C = fgetc(this->f);
}
void TokStrmRewind(TokStrm *this)
{
	rewind(this->f);
	this->C = fgetc(this->f);
}
void TokStrmNext(TokStrm *this)
{
	while (isspace(this->C))
	{
		this->C = fgetc(this->f);
	}

	if (this->C != EOF)
	{
		if (isalnum(this->C))
		{
			uint8_t i = 0;
			do
			{
				this->tk[i++] = this->C;
				this->C = fgetc(this->f);
			} while (isalnum(this->C));
			this->tk[i] = 0;
		}
		else
		{
			this->tk[0] = this->C;
			this->C = fgetc(this->f);
		}
	}
}
bool TokStrmEol(TokStrm *this)
{
	while (isspace(this->C))
	{
		if (this->C == '\n')
		{
			return true;
		}
	}
	return false;
}