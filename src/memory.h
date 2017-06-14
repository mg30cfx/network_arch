#ifndef MEMORY_H_
#define MEMORY_H_

struct memory_type
{
	int num_a;
	int num_b;
	int result;
};

typedef struct memory_type *SUM;

SUM memory_handler;

void set_memory(int v1, int v2);
void somma(void);
void sottrazione(void);

#endif /* MEMORY_H_ */
