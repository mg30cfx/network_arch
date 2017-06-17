#ifndef NETWORK_ARCH_H_
#define NETWORK_ARCH_H_

#include "memory.h"
#include "errors.h"
#include "config.h"

/*
 * create var objects that you need here
 */

ERRORS errors_handler;
MEMORY memory_handler;
NET_CONFIG net_cfg_handler;
INSTR_CONFIG instr_cfg_handler;
PATH_CONFIG path_cfg_handler;

#endif /* NETWORK_ARCH_H_ */
