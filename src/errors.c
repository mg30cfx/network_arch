#include <syslog.h>
#include <stdlib.h>

#include "errors.h"

int write_errors(void)
{
	return EXIT_SUCCESS;
}

int write_logfile(void)
{
	openlog(NULL, LOG_PID|LOG_CONS, LOG_USER);
	syslog(LOG_INFO, "-> network program <- started and stopped");
	closelog();

	return EXIT_SUCCESS;
}
