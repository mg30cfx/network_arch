#include <stdio.h>
#include <stdlib.h>

#include "lecroy_666.h"

/*
 *	Object constructor
 */

LECROY_XXX new_lecroy_xxx_handler(void)
{
	return malloc(sizeof(struct lecroy_xxx_values));
}

/*
 * Object destructor
 */

void delete_lecroy_xxx_handler(LECROY_XXX osc_handler)
{
	free(osc_handler);
}


