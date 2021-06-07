#ifndef _MALLOC_
#define _MALLOC_


typedef long Align;
union header
{
	struct
	{
        	union header *ptr;
        	unsigned size;
	} s;
	Align x;
};
typedef union header Header;

void *naive_malloc(size_t size);
#endif
