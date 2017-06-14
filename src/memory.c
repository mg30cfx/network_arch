#include <stdio.h>
#include <stdlib.h>

#include "memory.h"

void set_memory(int v1, int v2)
{
	memory_handler->num_a = v1;
	memory_handler->num_b = v2;
}

void somma(void)
{
	memory_handler->result = memory_handler->num_a + memory_handler->num_b;
}

void sottrazione(void)
{
	memory_handler->result = memory_handler->num_a - memory_handler->num_b;
}
