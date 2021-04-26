#include <glib.h>

int main(int argc, char *argv[])
{
    GKeyFile *keyfile;
    GError *error = NULL;

    keyfile = g_key_file_new();

    g_key_file_set_integer(keyfile, "group1", "key1", 100);
    g_key_file_set_string(keyfile, "group1", "key2", "hey");

    g_key_file_set_boolean(keyfile, "group2", "key1", TRUE);
    g_key_file_set_double(keyfile, "group2", "key2", 55.688);

    if (!g_key_file_save_to_file(keyfile, argv[1], &error)) {
        g_printerr("Error: %s\n", error->message);
        g_error_free(error);
        return 1;
    }
    g_key_file_free(keyfile);
    return 0;
}
