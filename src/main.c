#include "token.h"

int main()
{
	TokStrm t;
	TokStrmInit(&t, "../../tests/test.c");

	TokStrmNext(&t);
	while (t.tk[0])
	{
		puts(t.tk);
		TokStrmNext(&t);
	}
}
