#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/utsname.h>

#include "utility.h"

/*
 * Check os version
 */

char *get_platform_name(void)
{
	return (PLATFORM_NAME == NULL) ? "" : PLATFORM_NAME;
}

/*
 * Check if given file with path exist on disk
 */

int check_file_exist(char *path)
{
	if (access(path, F_OK) != -1)
	{
		printf("Something\n");
		return EXIT_SUCCESS;
	}
	else
	{
		printf("Something NOK\n");
		return EXIT_FAILURE;
	}
}

/*
 * Get system informations
 */

void get_sys_info(void)
{
	struct utsname uname_pointer;

	uname(&uname_pointer);

	printf("System name - %s\n", uname_pointer.sysname);
	printf("Nodename    - %s\n", uname_pointer.nodename);
	printf("Release     - %s\n", uname_pointer.release);
	printf("Version     - %s\n", uname_pointer.version);
	printf("Machine     - %s\n", uname_pointer.machine);
	printf("Domain name - %s\n", uname_pointer.__domainname);
}
