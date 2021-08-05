#include <glib.h>
#include <gio/gio.h>

static gboolean
proc_mounts_changed(GIOChannel *channel,
                    GIOCondition cond,
                    gpointer user_data)
{
    if (cond & G_IO_ERR) {
        g_print("mounts changed!\n"); 
    }
    return TRUE;
}

int
main(int argc, char *argv[])
{
    GIOChannel *proc_mounts_channel;
    GSource *proc_mounts_watch_source;
    GError *error = NULL;
    GMainLoop *loop;

    proc_mounts_channel = g_io_channel_new_file("/proc/mounts", "r", &error);
    if (proc_mounts_channel == NULL) {
        g_warning("Error creating IO channel for %s: %s\n",
                  "/proc/mounts",
                  error->message);
        g_error_free(error);
        return error->code;
    }

    proc_mounts_watch_source = g_io_create_watch(proc_mounts_channel, G_IO_ERR);
    g_source_set_callback(proc_mounts_watch_source,
                          (GSourceFunc) proc_mounts_changed,
                          NULL,
                          NULL);
    g_source_attach(proc_mounts_watch_source,
                    g_main_context_get_thread_default());
    g_source_unref(proc_mounts_watch_source);
    g_io_channel_unref(proc_mounts_channel);

    /* Run the main loop, program can be ended with CTRL+C */
    loop = g_main_loop_new(NULL, FALSE);
    g_main_loop_run(loop);

    g_main_loop_unref(loop);
    return 0;
}