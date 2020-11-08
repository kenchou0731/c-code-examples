/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#define _GNU_SOURCE
#include <stdio.h>
#include "myobj.h"

int
main (int argc, char *argv[])
{
    GError *err = NULL;
    GDBusKenTestMyObject *proxy = NULL;

    proxy = gdbus_ken_test_my_object_proxy_new_for_bus_sync(G_BUS_TYPE_SYSTEM,
                                                            G_DBUS_PROXY_FLAGS_NONE,
                                                            "example.ken.testdbus",
                                                            "/example/ken/testdbus/MyObject/1",
                                                            NULL,
                                                            &err);
    if (proxy == NULL) {
        g_printerr ("Failed to create proxy: %s\n", err->message);
        return 0;
    }

    gdbus_ken_test_my_object_call_method1_sync(proxy,
                                               1,
                                               NULL,
                                               &err);
    g_object_unref(proxy);

    /*******************************************************/
    proxy = gdbus_ken_test_my_object_proxy_new_for_bus_sync(G_BUS_TYPE_SYSTEM,
                                                            G_DBUS_PROXY_FLAGS_NONE,
                                                            "example.ken.testdbus",
                                                            "/example/ken/testdbus/MyObject/2",
                                                            NULL,
                                                            &err);
    if (proxy == NULL) {
        g_printerr ("Failed to create proxy: %s\n", err->message);
        return 0;
    }

    gdbus_ken_test_my_object_call_method1_sync(proxy,
                                               2,
                                               NULL,
                                               &err);
    g_object_unref(proxy);

    return 0;
}
