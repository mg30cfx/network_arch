#include <glib.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

int read_config()
{
	GKeyFile *keyfile;
	GKeyFileFlags flags;
	GError *error = NULL;

	keyfile = g_key_file_new();
	flags = G_KEY_FILE_KEEP_COMMENTS | G_KEY_FILE_KEEP_TRANSLATIONS;

	g_key_file_load_from_file (keyfile, "../ini/config.ini", flags, &error);

	strncpy(net_cfg_handler->ip, g_key_file_get_string(keyfile,"network","ip",NULL), IP_LEN);

	return EXIT_SUCCESS;
}
