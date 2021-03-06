#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "malloc.h"

size_t align(size_t size);
/**
 * naive_malloc -  naive malloc
 * @size: the size needed to be allocated
 * Return: Pointer to the address allocated
 */
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

	h = brk_base;
	brk_base = ((void *)((char *)brk_base + size));

	x += 1;
	memcpy(h, &size, sizeof(size));
	h = ((char *)h) + sizeof(size_t);
	return (h);
}
/**
 * align - round the size to be allocated
 * @size: the size needed to be allocated
 * Return: new size
 */
size_t align(size_t size)
{
	if (size % 8 == 0)
		return (size);
	return (size + (8 - (size % 8)));
}
