#include <stdio.h>
#include <glib.h>
#include "print_table.h"


int main(int argc, char *argv[])
{
    PrintTable *tb;

    tb = table_new(3);
    // table_add_entry(tb, 1, "123");
    // table_add_entry(tb, 5, "123", "456", "789", "789", "789");
    table_add_entry(tb, 3, "NAME", "TYPE", "VALUE");
    table_add_entry(tb, 3, "Hello", "A", "100");
    table_add_entry(tb, 3, "World", "A", "20");
    table_add_entry(tb, 3, "Happy", "B", "3");

    table_print(tb);

    g_object_unref(tb);
    return 0;
}
