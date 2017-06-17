#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "config.h"


/*
 * Object network config constructor
 */

NET_CONFIG new_netconf_handler(void)
{
	return malloc(sizeof(struct net_conf));
}

/*
 * Object network config destructor
 */

void delete_netconf_handler(NET_CONFIG net_cfg_handler)
{
	free(net_cfg_handler);
}

/*
 *	Get current pathname
 */

int *get_path(char *cwd)
{
	getcwd(cwd, 1024);

	return EXIT_SUCCESS;
}

/*
 * Read network config from INI file
 */

int read_net_config(NET_CONFIG net_cfg_handler)
{
	GKeyFile *keyfile;
	GKeyFileFlags flags;
	GError *error = NULL;

	char cwd[1024] = {0};
	get_path(cwd);
	strcat(cwd, "/ini/config.ini");

	keyfile = g_key_file_new();
	flags = G_KEY_FILE_KEEP_COMMENTS | G_KEY_FILE_KEEP_TRANSLATIONS;

	g_key_file_load_from_file (keyfile, cwd, flags, &error);

	strncpy(net_cfg_handler->ip, g_key_file_get_string(keyfile,"network","ip",NULL), IP_LEN);
	net_cfg_handler->port = g_key_file_get_integer(keyfile,"network","port",NULL);

	return EXIT_SUCCESS;
}
