#include "parse.h"
#include "token.h"
#include <stdbool.h>
#include <stdlib.h>

bool IsOprt(const char s)
{
	switch (s)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
	case '%':
	case '&':
	case '|':
		return true;
	default:
		return false;
	}
}

int64_t PrsInt(AsmBlock *this)
{
	int64_t n;
	if (*this->strm.tk == '(')
	{
		TokStrmNext(&this->strm);
		n = PrsLit(this);
		TokStrmNext(&this->strm);
	}
	else if (*this->strm.tk == '~')
	{
		TokStrmNext(&this->strm);
		n = ~PrsInt(this);
	}
	else
	{
		n = strtoll(this->strm.tk, NULL, 0);
	}
	TokStrmNext(&this->strm);
	return n;
}

int64_t CharMath(const int64_t left, const char s, const int64_t right)
{
	switch (s)
	{
	case '+':
		return left + right;
	case '-':
		return left - right;
	case '*':
		return left * right;
	case '/':
		return left / right;
	case '^':
		return left ^ right;
	case '%':
		return left % right;
	case '&':
		return left & right;
	case '|':
		return left | right;
	default:
		fprintf(stderr, "Attempted to perform arithmetic with something (%c) that is not an operator!\n", s);
		exit(EXIT_FAILURE);
	}
}

int64_t PrsLit(AsmBlock *this)
{
	int64_t base = PrsInt(this);

	while (*this->strm.tk && IsOprt(*this->strm.tk))
	{
		char op = *this->strm.tk;
		TokStrmNext(&this->strm);
		base = CharMath(base, op, PrsInt(this));
	}
	return base;
}
