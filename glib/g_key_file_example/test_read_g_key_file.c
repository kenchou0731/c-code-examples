#include <glib.h>

int main(int argc, char *argv[])
{
    GKeyFile *keyfile;
    GKeyFileFlags flags;
    GError *error = NULL;

    keyfile = g_key_file_new();
    flags = G_KEY_FILE_KEEP_COMMENTS | G_KEY_FILE_KEEP_TRANSLATIONS;

    if (!g_key_file_load_from_file(keyfile, argv[1], flags, &error)) {
        g_printerr("Error: %s\n", error->message);
        g_error_free(error);
        return 1;
    }

    g_print("[group1]\n");
    g_print("key1=%d\n", g_key_file_get_integer(keyfile, "group1", "key1", NULL));
    g_print("key2=%s\n", g_key_file_get_string(keyfile, "group1", "key2", NULL));

    g_print("[group2]\n");
    g_print("key1=%s\n", g_key_file_get_boolean(keyfile, "group2", "key1", NULL) ? "true" : "false");
    g_print("key2=%lf\n", g_key_file_get_double(keyfile, "group2", "key2", NULL));

    g_key_file_free(keyfile);
    return 0;
}
