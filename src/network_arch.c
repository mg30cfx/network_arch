#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memory.h"
#include "errors.h"

#ifdef __linux
	char *os = "linux";
#else
	char *os = "other";
#endif

void help(void)
{

}

int main(int argc, char *argv[]) {

	memory_handler = malloc(sizeof(struct memory_type));
	errors_handler = malloc(sizeof(struct errors_type));

	set_memory(1, 10);
	somma();
	printf("result: %d\n", memory_handler->result);


	set_memory(10, 31);
	sottrazione();
	printf("result: %d\n", memory_handler->result);

	memset(errors_handler->msg, 0, ERROR_STR_SIZE);
	strncpy(errors_handler->msg, "-> network program <- started and stopped", ERROR_STR_SIZE);
	write_logfile();

	free(memory_handler);
	free(errors_handler);

	return EXIT_SUCCESS;
}
