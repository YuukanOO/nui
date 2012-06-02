#include <stdlib.h>

void* nui_alloc(size_t size)
{
	return malloc(size);
}
// -----------------------------------------------------------------
void nui_free(void* ptr)
{
	free(ptr);
}