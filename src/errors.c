#include <syslog.h>
#include <stdlib.h>

#include "errors.h"

/*
 * Object constructor
 */

ERRORS new_err_handler(void)
{
	return malloc(sizeof(struct errors_type));
}

/*
 * Object destructor
 */

void delete_err_handler(ERRORS errors_handler)
{
	free(errors_handler);
}

/*
 * Write errors on log file
 */

int write_logfile(ERRORS errors_handler, char *msg)
{
	openlog(NULL, LOG_PID|LOG_CONS, LOG_USER);
	syslog(LOG_INFO, msg, ERROR_STR_SIZE);
	closelog();

	return EXIT_SUCCESS;
}
