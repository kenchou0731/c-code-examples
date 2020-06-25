#include<glib.h>

GMainLoop* loop;

int main(int argc, char *argv[])
{
    g_print("g_main_loop_new\n");
    loop = g_main_loop_new(NULL, FALSE);

    g_print("g_main_loop_run\n");
    g_main_loop_run(loop);

    g_print("g_main_loop_unref\n");
    g_main_loop_unref(loop);
    return 0;
}