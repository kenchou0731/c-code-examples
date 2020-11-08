#include <signal.h>
#include <syslog.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include <gio/gio.h>
#include <glib-unix.h>

#include "myobj.h"

GMainLoop* loop;

/*****************************************************************************/
gboolean
on_handle_method1(GDBusKenTestMyObject *skeleton,
                  GDBusMethodInvocation *invocation,
                  gint arg1,
                  gpointer user_data)
{
    g_print("on_handle_method1: %d\n", arg1);
    gdbus_ken_test_my_object_complete_method1(skeleton,
                                              invocation);
    return TRUE;
}
/*****************************************************************************/
static gboolean
quit_cb(gpointer user_data)
{
    if (loop)
        g_idle_add((GSourceFunc) g_main_loop_quit, loop);
    else
        exit (0);
    return FALSE;
}

static void
bus_acquired_cb(GDBusConnection *connection,
                const gchar *name,
                gpointer user_data)
{
    g_print ("bus acquired\n");
}

static void
name_acquired_cb(GDBusConnection *connection,
                 const gchar *name,
                 gpointer user_data)
{
    GDBusKenTestMyObject *skeleton1, *skeleton2;

    g_print ("Service name '%s' was acquired\n", name);

    skeleton1 = gdbus_ken_test_my_object_skeleton_new();
    skeleton2 = gdbus_ken_test_my_object_skeleton_new();

    g_signal_connect(skeleton1,
                     "handle-method1",
                     G_CALLBACK(on_handle_method1),
                     NULL);
    g_signal_connect(skeleton2,
                     "handle-method1",
                     G_CALLBACK(on_handle_method1),
                     NULL);

    g_dbus_interface_skeleton_export(G_DBUS_INTERFACE_SKELETON(skeleton1),
                                     connection,
                                     "/example/ken/testdbus/MyObject/1",
                                     NULL);
    g_dbus_interface_skeleton_export(G_DBUS_INTERFACE_SKELETON(skeleton2),
                                     connection,
                                     "/example/ken/testdbus/MyObject/2",
                                     NULL);
}

static void
name_lost_cb(GDBusConnection *connection,
             const gchar *name,
             gpointer user_data)
{
    /* Note that we're not allowing replacement, so once the name acquired, the
     * process won't lose it. */
    if (!name)
        g_print("Could not get the system bus. Make sure "
                "the message bus daemon is running\n!");
    else
        g_print("Could not acquire the '%s' service name \n", name);

    g_main_loop_quit (loop);
}
/*****************************************************************************/

int main(int argc, char* argv[])
{
    guint name_id;

    g_unix_signal_add (SIGTERM, quit_cb, NULL);
    g_unix_signal_add (SIGINT, quit_cb, NULL);

    name_id = g_bus_own_name (G_BUS_TYPE_SYSTEM,
                              "example.ken.testdbus",
                              G_BUS_NAME_OWNER_FLAGS_NONE,
                              bus_acquired_cb,
                              name_acquired_cb,
                              name_lost_cb,
                              NULL,
                              NULL);

    g_print("g_main_loop_new\n");
    loop = g_main_loop_new(NULL, FALSE);
    g_main_loop_run(loop);

    g_print("g_main_loop_unref\n");
    g_main_loop_unref(loop);
    return 0;
}
