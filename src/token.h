#pragma once

#include <stdbool.h>
#include <stdio.h>

#define TK_MAX 32

typedef struct
{
	FILE *f;
	int C;
	char tk[TK_MAX];
} TokStrm;

void TokStrmInit(TokStrm *this, const char *path);
void TokStrmRewind(TokStrm *this);
void TokStrmNext(TokStrm *this);
bool TokStrmEol(TokStrm *this);