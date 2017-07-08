#ifndef LECROY_666_H_
#define LECROY_666_H_

/*
 * General define
 */

#define LECROY_STRLEN	2048

/*
 * Lecroy xxx command
 */

#define LECROY_xxx_IDN		"*IDN?\n"		/* return DMM ID */
#define LECROY_xxx_CLS		"*RST\n"		/* reset instruments */

/*
 * Reading channels
 */

struct lecroy_xxx_values
{
	int ch01;
	int ch02;
	int ch03;
	int ch04;
	char tdiv[LECROY_STRLEN];		/* set OSC time division */
	char vdiv[LECROY_STRLEN];		/* set OSV volt division */
	};

/*
 * Define handler
 */

typedef struct lecroy_xxx_values *LECROY_XXX;

/*
 * Define functions prototype
 */

LECROY_XXX new_lecroy_xxx_handler(void);
void delete_lecroy_xxx_handler(LECROY_XXX osc_handler);


#endif /* LECROY_666_H_ */
