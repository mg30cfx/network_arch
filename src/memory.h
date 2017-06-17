#ifndef MEMORY_H_
#define MEMORY_H_

/*
 * Object struct definition
 */

struct memory_type
{
	int num_a;
	int num_b;
	int result;
};

typedef struct memory_type *MEMORY;

/*
 * Function prototype
 *
 */

MEMORY new_mem_handler(void);
void delete_mem_handler(MEMORY memory_handler);
int set_memory(MEMORY memory_handler, int v1, int v2);

#endif /* MEMORY_H_ */
