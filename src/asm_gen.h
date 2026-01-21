#pragma once

#include <stdint.h>

typedef enum : uint8_t
{
	MEM_STATC,
	MEM_REGST,
	MEM_STACK,
} MemKeyType;

typedef struct
{
	MemKeyType type;
	int64_t val;
} MemKey;

typedef struct
{
	//
} MemPicker;