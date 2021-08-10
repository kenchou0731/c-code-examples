#include <stdio.h>
#include <glib.h>

void print_list(GList *list) {
    GList *l;

    for (l = list; l != NULL; l = l->next) {
        printf("%s ", l->data);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    // Notice that these are initialized to the empty list.
    GList *string_list = NULL;

    // This is a list of strings.
    string_list = g_list_append(string_list, "first");
    string_list = g_list_append(string_list, g_strdup("second"));
    string_list = g_list_append(string_list, "third");

    print_list(string_list);
    printf("---------------\n");

    string_list = g_list_remove(string_list, "second");
    print_list(string_list);
    printf("---------------\n");
    
    GList *l = g_list_find_custom(string_list, "second", (GCompareFunc) g_strcmp0);
    string_list = g_list_remove_link(string_list, l);
    g_list_free1(l);
    print_list(string_list);
    printf("---------------\n");

    g_list_free(string_list);
    return 0;
}
