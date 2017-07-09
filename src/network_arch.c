#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#include "network_arch.h"
#include "utility.h"

/*
 * Help function
 */

void help(void)
{
	printf("print help on screen\n");
	exit(EXIT_FAILURE);
}

/*
 * Check command line options parameters
 * and set main program parameters
 */

int cmdline_parser(int argc, char *argv[], CMDLINE_PARAMS cmdl_hand)
{
	int c = 0;
	int index = 0;

	/*
	 * init command line parameters struct
	 */
	memset(cmdl_hand, 0, sizeof(struct cmd_line_params));

	/*
	 * Parse command line
	 */

	while ((c = getopt (argc, argv, "hdv:c:l:s")) != -1)
	{
		switch (c)
		{
		case 'h':
			help();
			break;

		case 'd':
			cmdl_hand->demo_mode = 1;
			break;

		case 'v':
			cmdl_hand->verbose_mode = 1;
			break;

		case 'c':
			strncpy(cmdl_hand->config_ini, optarg, CMD_LINE_PARAMS_LEN);
			break;

		case 'l':
			cmdl_hand->verbosity_level = atoi(optarg);
			break;

		case 's':
			cmdl_hand->simulate_dev = 1;
			break;

		default:
			for (index = optind; index < argc; index++)
			    printf ("Non-option argument %s\n", argv[index]);
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}

/*
 * MAIN FUNCTION
 */

int main(int argc, char *argv[]) {

	/*
	 * Get system informations
	 */

	printf("OS version : %s\n", get_platform_name());
	get_sys_info();

	/*
	 * Create command line parser handler
	 */

	CMDLINE_PARAMS cmdline_handler;
	cmdline_handler = malloc(sizeof(struct cmd_line_params));
	if (cmdline_parser(argc, argv, cmdline_handler) != EXIT_SUCCESS)
	{
		fprintf(stderr, "Error in command line parameters. Program exit\n");
		free(cmdline_handler);
		help();
	}

	/*
	 * Check if main configuration INI file exist, otherwise program aborted
	 */

	if (check_file_exist(cmdline_handler->config_ini) != EXIT_SUCCESS)
	{
		fprintf(stderr, "Unable to read INI file in %s:. Program exit\n", cmdline_handler->config_ini);
		free(cmdline_handler);
		help();
	}

	/*
	 * Create memory handler
	 */
	memory_handler = new_mem_handler();
	// set_memory(memory_handler, 1, 10);  // TEST !

	/*
	 * Create error and info handler
	 */
	errors_handler = new_err_handler();
	write_logfile(errors_handler, "-> network program started");
	/*
	 * Now, parse INI file and retrieve all configuration parameters
	 */

	net_cfg_handler = new_netconf_handler();

	read_net_config(net_cfg_handler);


	/*
	 * Free memory before program exit
	 */

	delete_netconf_handler(net_cfg_handler);
	delete_mem_handler(memory_handler);

	free(cmdline_handler);

	write_logfile(errors_handler, "-> network program stopped");
	delete_err_handler(errors_handler);

	return EXIT_SUCCESS;
}
