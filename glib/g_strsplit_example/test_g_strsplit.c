#include <glib.h>

int main(int argc, char *argv[])
{
    gchar *in = "Hello world 123";
    gchar **out;
    int i;

    out = g_strsplit_set(in, " ", 0);
    i = 0;
    for (i = 0; out[i] != NULL; i++) {
        g_print("%s\n", out[i]);
    }

    g_strfreev(out);
    return 0;
}
