#include <glib.h>

GMainLoop* loop;
gint counter = 10;

gboolean callback(gpointer arg)
{
    g_print(".");
    if (--counter == 0) {
        g_print("\n");
        g_main_loop_quit(loop);
        return FALSE;
    }
    return TRUE;
}
 
int main(int argc, char* argv[])
{
    g_print("g_main_loop_new\n");
    loop = g_main_loop_new(NULL, FALSE);

    g_timeout_add(100, callback, NULL);
    g_print("g_main_loop_run\n");
    g_main_loop_run(loop);
    g_print("g_main_loop_unref\n");
    g_main_loop_unref(loop);
    return 0;
}