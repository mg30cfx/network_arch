#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <pcap.h>

#include "memory.h"
#include "errors.h"

int main(void) {

	memory_handler = malloc(sizeof(struct memory_type));
	errors_handler = malloc(sizeof(struct errors_type));

	set_memory(1, 10);
	somma();
	printf("result: %d\n", memory_handler->result);


	set_memory(10, 31);
	sottrazione();
	printf("result: %d\n", memory_handler->result);

	write_logfile();

	free(memory_handler);
	free(errors_handler);

	return EXIT_SUCCESS;
}
