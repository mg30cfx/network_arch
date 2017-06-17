#include <stdio.h>
#include <stdlib.h>

#include "memory.h"

/*
 *	Object constructor
 */

MEMORY new_mem_handler(void)
{
	return malloc(sizeof(struct memory_type));
}

/*
 * Object destructor
 */

void delete_mem_handler(MEMORY memory_handler)
{
	free(memory_handler);
}

/*
 * Set memory with custom values
 */

int set_memory(MEMORY memory_handler, int v1, int v2)
{
	memory_handler->num_a = v1;
	memory_handler->num_b = v2;

	return EXIT_SUCCESS;
}

