#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "malloc.h"

size_t align(size_t size);

void *naive_malloc(size_t size)
{
	static int x;
	static void *brk_base;

	if (size == 0)
		return (NULL);

	size += sizeof(size_t);
	size = align(size);

	if (!x)
	{
		x = 0;
		brk_base = sbrk(sysconf(_SC_PAGESIZE));
		if (brk_base == (void *)-1)
		return (NULL);
	}

	/*for (i = 0; i < x; i += 1)*/
	{
		brk_base = ((void *)((char *)brk_base + size));
	}

	x += 1;
	memcpy(brk_base, &size, sizeof(size));
	brk_base = ((char *)brk_base) + sizeof(size_t);
	return (brk_base);
}

size_t align(size_t size)
{
	if (size % 8 == 0)
		return (size);
	return (size + (8 - (size % 8)));
}
