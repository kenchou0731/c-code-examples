#include <gmodule.h>
#include <glib.h>
typedef int (*SimpleFunc) (void);

int main(int argc, char *argv[])
{
    GModule *module = NULL;
    gpointer func;
    SimpleFunc f_a;
    int rc;

    if (!g_module_supported()) {
        g_print("Dynamic Opening of modules is not supported\n");
        return 1;
    }

    /*
     * G_MODULE_BIND_LAZY is overridden and the module is opened
     * with G_MODULE_BIND_LOCAL flag
     */
    module = g_module_open(argv[1], G_MODULE_BIND_LAZY);

    if (module && g_module_symbol(module, "module_init", &func)) {
        f_a = (SimpleFunc) func;
        rc = f_a();
        g_print("gmodule %s returns %d\n", g_module_name(module), rc);
    } else {
        g_print("Error quering symbol\n");
        return 1;
    }

    g_module_close(module);
    return 0;
}
