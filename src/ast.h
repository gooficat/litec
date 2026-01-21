#pragma once

#include <stdint.h>

typedef enum : uint8_t
{
	AST_NODE_NONE,
	AST_NODE_SCOP,
	AST_NODE_FDEF,
	AST_NODE_VDEF,
	AST_NODE_ASSI,
	AST_NODE_VREF,
	AST_NODE_LITR,
	AST_NODE_OPER,
	AST_NODE_CALL,
} ASTNodeType;