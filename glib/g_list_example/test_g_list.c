#include <stdio.h>
#include <glib.h>

int main(int argc, char** argv) {
    // Notice that these are initialized to the empty list.
    GList *string_list = NULL, *number_list = NULL;
    GList *l;

    // This is a list of strings.
    string_list = g_list_append(string_list, "first");
    string_list = g_list_append(string_list, "second");
    string_list = g_list_append(string_list, "third");

    for (l = string_list; l != NULL; l = l->next) {
        printf("%s ", l->data);
    }
    printf("\n");

    // This is a list of integers.
    number_list = g_list_append(number_list, GUINT_TO_POINTER(666));
    number_list = g_list_append(number_list, GUINT_TO_POINTER(777));
    for (l = number_list; l != NULL; l = l->next) {
        printf("%d ", GPOINTER_TO_UINT(l->data));
    }
    printf("\n");

    g_list_free(string_list);
    g_list_free(number_list);
    return 0;
}
