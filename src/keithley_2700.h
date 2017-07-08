#ifndef KEITHLEY_2700_H_
#define KEITHLEY_2700_H_

/*
 * KEITHLEY 2700 command
 */

#define KTH_2700_IDN		"*IDN?\n"		/* return DMM ID */
#define KTH_2700_CLS		"*RST\n"		/* reset instruments */

/*
 * Reading channels
 */

struct kth_2700_values
{
	int ch01;
	int ch02;
	int ch03;
	int ch04;
	int ch05;
	int ch06;
	int ch07;
	int ch08;
	int ch09;
	int ch10;
	int ch11;
	int ch12;
	int ch13;
};

/*
 * Define handler
 */

typedef struct kth_2700_values *KTH_2700;

/*
 * Define functions prototype
 */

KTH_2700 new_kth_2700_handler(void);
void delete_kth_2700_handler(KTH_2700 dmm_handler);


#endif /* KEITHLEY_2700_H_ */
