#ifndef _MALLOC_
#define _MALLOC_


typedef long Align;
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
/**
 * union header- header
 * @test_s: ...
 * @x: ..
 */
union header
{
	struct s test_s;
	Align x;
};
typedef union header Header;

void *naive_malloc(size_t size);
void *_malloc(size_t size);
void _free(void *ptr);
#endif
