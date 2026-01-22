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

	uint8_t i = 0;
	if (this->C != EOF)
	{
		if (isalnum(this->C))
		{
			do
			{
				this->tk[i++] = this->C;
				this->C = fgetc(this->f);
			} while (isalnum(this->C));
		}
		else
		{
			this->tk[i++] = this->C;
			this->C = fgetc(this->f);
		}
	}
	this->tk[i] = 0;
}
bool TokStrmEol(TokStrm *this)
{
	while (isspace(this->C))
	{
		this->C = fgetc(this->f);
		if (this->C == '\n')
		{
			return true;
		}
	}
	return false;
}