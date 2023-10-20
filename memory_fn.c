#include "SimpleShell.h"

/**
 * custom_allocate - Allocate memory for a specified number of elements of a given size
 * @num_elements: Number of elements in the array
 * @element_size: Size of each element in bytes
 * Return: A void pointer to the allocated memory
 */
void *custom_allocate(unsigned int num_elements, unsigned int element_size)
{
	char *memory_ptr;
	unsigned int i;

	if (num_elements == 0 || element_size == 0)
		return NULL;

	memory_ptr = malloc(num_elements * element_size);
	if (memory_ptr == NULL)
		return NULL;

	for (i = 0; i < num_elements * element_size; i++)
		memory_ptr[i] = 0;

	return memory_ptr;
}
