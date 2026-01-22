#pragma once

#include <malloc.h>

#define PushM(v, ...)                                                                                                  \
	do                                                                                                                 \
	{                                                                                                                  \
		if (++v.size > v.capacity)                                                                                     \
		{                                                                                                              \
			v.capacity *= 2;                                                                                           \
			v.data = realloc(v.data, sizeof(*v.data) * v.capacity);                                                    \
		}                                                                                                              \
		v.data[v.size - 1] = __VA_ARGS__;                                                                              \
	} while (0)

#define Push(v, ...) PushM((v), __VA_ARGS__)

#define PopM(v)                                                                                                        \
	do                                                                                                                 \
	{                                                                                                                  \
		if (v.capacity / 2 > --v.size)                                                                                 \
		{                                                                                                              \
			v.capacity /= 2;                                                                                           \
			v.data = realloc(v.data, sizeof(*v.data * v.capacity);)                                                    \
		}                                                                                                              \
	} while (0)

#define Pop(v) PopM((v))

#define VecStruc(t, a)                                                                                                 \
	{                                                                                                                  \
		t *data;                                                                                                       \
		a size;                                                                                                        \
		a capacity;                                                                                                    \
	}

#define InitVecM(v)                                                                                                    \
	do                                                                                                                 \
	{                                                                                                                  \
		v.data = malloc(sizeof(*v.data));                                                                              \
		v.size = 0;                                                                                                    \
		v.capacity = 1;                                                                                                \
	} while (0)

#define InitVec(v) InitVecM((v))