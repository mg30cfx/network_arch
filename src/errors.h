#ifndef ERRORS_H_
#define ERRORS_H_

#define ERROR_STR_SIZE			8912

#define USER_WRONG_COMPUTING 	2
#define USER_RIGHT_COMPUTING	3

/*
 * "Object" struct definition
 */

struct errors_type
{
	char msg_format[ERROR_STR_SIZE];
	int error_num;
};

typedef struct errors_type *ERRORS;

/*
 * Function prototype
 *
 */

ERRORS new_err_handler(void);
void delete_err_handler(ERRORS errors_handler);
int write_logfile(ERRORS errors_handler, char *msg);

#endif /* ERRORS_H_ */
