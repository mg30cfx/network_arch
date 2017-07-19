#ifndef SPACE_H_
#define SPACE_H_

#include "memory.h"
#include "errors.h"
#include "config.h"

#include "dmm.h"
#include "osc.h"

#define CMD_LINE_PARAMS_LEN		512

/*
 * Command line parameters
 */

struct cmd_line_params
{
	char config_ini[CMD_LINE_PARAMS_LEN];		/* full path of ini file */
	int verbose_mode;							/* set verbose mode on / off */
	int debug_mode;								/* set debug mode on / off */
	int verbosity_level;						/* set verbosity level 1 - 3 */
	int demo_mode;								/* start program in demo mode */
	int simulate_dev;							/* start program with all or some devices simulated
													set the list of simulated device in ini file
												*/
};

typedef struct cmd_line_params *CMDLINE_PARAMS;

/*
 * create var objects that you need here
 */

ERRORS errors_handler;
MEMORY memory_handler;
NET_CONFIG net_cfg_handler;
INSTR_CONFIG instr_cfg_handler;
PATH_CONFIG path_cfg_handler;

/*
 * Prototype function
 */

int cmdline_parser(int argc, char *argv[], CMDLINE_PARAMS cmdl_hand);

#endif /* SPACE_H_ */
