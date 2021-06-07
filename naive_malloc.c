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

	void *h;
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
h = brk_base;
	if (x > 0)
	{
        	/*h = ((void *)((char *)brk_base));*/
		brk_base = ((void *)((char *)brk_base + size));
	}

	x += 1;
	/*h = brk_base;
	h = ((void *)((char *)brk_base - size + sizeof(size_t)));*/
	memcpy(h, &size, sizeof(size));
	brk_base = ((char *)h) + sizeof(size_t);
	return (brk_base);
}

size_t align(size_t size)
{
	if (size % 8 == 0)
		return (size);
	return (size + (8 - (size % 8)));
}
