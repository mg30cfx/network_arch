#include <stdio.h>
#include <stdlib.h>

#include "utility.h"

/*
 * Check os version
 */

char *get_platform_name(void)
{
	return (PLATFORM_NAME == NULL) ? "" : PLATFORM_NAME;
}
