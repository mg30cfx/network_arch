#ifndef CONFIG_H_
#define CONFIG_H_

#define INSTR_TYPE_STR_LEN	512
#define IP_LEN				15
#define PATH_LEN			256

/*
 * Object net config struct definition
 */

struct net_conf
{
	int port;
	char ip[IP_LEN];
};

typedef struct net_conf *NET_CONFIG;

/*
 * Object instruments config struct definition
 */

struct instruments_conf
{
	char osc_type[INSTR_TYPE_STR_LEN];
};

typedef struct instruments_conf *INSTR_CONFIG;

/*
 * Object pathname config struct definition
 */

struct path_config
{
	char error_path[PATH_LEN];
	char funct_path[PATH_LEN];
	char report_path[PATH_LEN];
};

typedef struct path_config *PATH_CONFIG;

/*
 * Function prototype
 *
 */

NET_CONFIG new_netconf_handler(void);
void delete_netconf_handler(NET_CONFIG net_cfg_handler);
int read_net_config(NET_CONFIG net_cfg_handler);

#endif /* CONFIG_H_ */
