#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "network_arch.h"

#ifdef __linux
	char *os = "linux";
#else
	char *os = "other";
#endif

void help(void)
{

}

int main(int argc, char *argv[]) {

	memory_handler = new_mem_handler();
	errors_handler = new_err_handler();
	net_cfg_handler = new_netconf_handler();

	read_net_config(net_cfg_handler);

	set_memory(memory_handler, 1, 10);  // TEST !

	write_logfile(errors_handler, "-> network program <- started and stopped");

	delete_netconf_handler(net_cfg_handler);
	delete_err_handler(errors_handler);
	delete_mem_handler(memory_handler);

	return EXIT_SUCCESS;
}
