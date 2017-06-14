#ifndef ERRORS_H_
#define ERRORS_H_

#define ERROR_STR_SIZE			8912

#define USER_WRONG_COMPUTING 	2
#define USER_RIGHT_COMPUTING	3


struct errors_type
{
	char msg[ERROR_STR_SIZE];
	int	error_num;
};

typedef struct errors_type *ERRORS;

ERRORS errors_handler;

int write_errors(void);
int write_logfile(void);

#endif /* ERRORS_H_ */
