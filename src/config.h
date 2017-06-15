#ifndef CONFIG_H_
#define CONFIG_H_

#define INSTR_TYPE_STR_LEN	512
#define IP_LEN				15
#define PATH_LEN			256

struct net_conf
{
	int port;
	char ip[IP_LEN];
};

struct instruments_conf
{
	char osc_type[INSTR_TYPE_STR_LEN];
};

struct path_config
{
	char error_path[PATH_LEN];
	char funct_path[PATH_LEN];
	char report_path[PATH_LEN];
};

typedef struct net_conf *NET_CONFIG;
typedef struct instruments_conf *INSTR_CONFIG;
typedef struct path_config *PATH_CONFIG;

NET_CONFIG net_cfg_handler;
INSTR_CONFIG instr_cfg_handler;
PATH_CONFIG path_cfg_handler;
int read_config(void);

#endif /* CONFIG_H_ */
