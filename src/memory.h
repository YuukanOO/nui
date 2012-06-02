/**
 *	Contains memory related members used by the NUI lib
 */

/**
 *	\brief		Alloc a block of memory
 *	\param		size 	:	size to allocate
 */
void* nui_alloc(size_t size);
/**
 *	\brief		Free a previously allocated block of memory
 *	\param		ptr		:	pointer to the block of memory
 */
void nui_free(void* ptr);