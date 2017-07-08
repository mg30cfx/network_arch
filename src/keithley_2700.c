#include <stdio.h>
#include <stdlib.h>

#include "keithley_2700.h"

/*
 *	Object constructor
 */

KTH_2700 new_kth_2700_handler(void)
{
	return malloc(sizeof(struct kth_2700_values));
}

/*
 * Object destructor
 */

void delete_kth_2700_handler(KTH_2700 dmm_handler)
{
	free(dmm_handler);
}
