#include "shell.h"

/**
 * _realloc -  reallocates a memory block using malloc and free
 * @ptr: Pointer to the memory previously allocated
 * @old_size: Size in bytes of the allocated space for ptr
 * @new_size: New size in bytes of the new memory block
 *
 * Description: reallocates a memory block using malloc and free
 * Return: Pointer to the new memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i, min_size;
	char *newptr;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		newptr = malloc(new_size);
		if (newptr == NULL)
			return (NULL);
		else
			return (newptr);
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (old_size > new_size)
		min_size = new_size;
	else
		min_size = old_size;

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (ptr);

	for (i = 0; i < min_size; i++)
		*(newptr + i) = *((char *)ptr + i);

	if (ptr != NULL)
		free(ptr);

	return (newptr);
}
