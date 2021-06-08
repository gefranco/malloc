#ifndef _MALLOC_
#define _MALLOC_


typedef long Align;

/**
 * union header- header
 * @s: ...
 * @x: ..
 */
union header
{
	struct s;
	Align x;
};
/**
 * struct s - struct
 * @ptr: ...
 * @size: ...
 */
struct s
{
	union header *ptr;
	unsigned int size;
};
typedef union header Header;

void *naive_malloc(size_t size);
#endif
