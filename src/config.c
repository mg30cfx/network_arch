#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "config.h"

int *get_path(char *cwd)
{
	getcwd(cwd, 1024);

	return EXIT_SUCCESS;
}

int read_config()
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
