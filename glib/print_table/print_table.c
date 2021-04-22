#include <stdio.h>
#include <string.h>
#include "print_table.h"

struct _PrintTablePrivate {
    guint num_of_columns;
    guint *columns_lengths;
    GList *entries;
};

G_DEFINE_TYPE_EXTENDED(PrintTable,
                       print_table,
                       G_TYPE_OBJECT,
                       0,
                       G_ADD_PRIVATE(PrintTable))

enum {
    PROP_0,
    PROP_NUM_OF_COLUMNS,
    PROP_LAST
};
static GParamSpec *properties[PROP_LAST];

/*****************************************************************************/


/*****************************************************************************/

static void set_property(GObject *object,
                         guint prop_id,
                         const GValue *value,
                         GParamSpec *pspec)
{
    PrintTable *self = PRINT_TABLE(object);
    int n, i;

    switch (prop_id) {
    case PROP_NUM_OF_COLUMNS:
        n = g_value_get_int(value);
        self->priv->num_of_columns = n;
        /* Init length */
        self->priv->columns_lengths = (guint *) g_malloc(n * sizeof(guint));
        for (i = 0; i < n; i++)
            self->priv->columns_lengths[i] = 0;
        break;
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
        break;
    }
}

static void get_property(GObject *object,
                         guint prop_id,
                         GValue *value,
                         GParamSpec *pspec)
{
    PrintTable *self = PRINT_TABLE(object);

    switch (prop_id) {
    case PROP_NUM_OF_COLUMNS:
        g_value_set_int(value, self->priv->num_of_columns);
        break;
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
        break;
    }
}

static void finalize(GObject *object)
{
    PrintTablePrivate *priv = PRINT_TABLE(object)->priv;
    GList *i;

    if (priv->columns_lengths != NULL)
        g_free(priv->columns_lengths);

    for (i = priv->entries; i != NULL; i = i->next) {
        g_list_free(i->data);
    }
    g_list_free(priv->entries);

    G_OBJECT_CLASS(print_table_parent_class)->finalize(object);
}

static void print_table_class_init(PrintTableClass *klass)
{
    GObjectClass *object_class = G_OBJECT_CLASS(klass);

    /* Virtual methods */
    object_class->set_property = set_property;
    object_class->get_property = get_property;
    object_class->finalize = finalize;

    /* Properties */
    properties[PROP_NUM_OF_COLUMNS] =
        g_param_spec_int(PRINT_TABLE_PROP_NUM_OF_COLUMNS,
                         "NumOfColumns",
                         "Number of columns in table",
                         1, 10, 1,
                         G_PARAM_CONSTRUCT_ONLY | G_PARAM_READWRITE);
    g_object_class_install_property(object_class, PROP_NUM_OF_COLUMNS, properties[PROP_NUM_OF_COLUMNS]);
}

static void print_table_init(PrintTable *self)
{
    /* Initialize private data */
    self->priv = G_TYPE_INSTANCE_GET_PRIVATE(self, G_TYPE_PRINT_TABLE, PrintTablePrivate);
    self->priv->num_of_columns = 1;
    self->priv->columns_lengths = NULL;
    self->priv->entries = NULL;
}

/*****************************************************************************/

PrintTable *table_new(guint num_of_columns)
{
    return g_object_new(G_TYPE_PRINT_TABLE,
                        PRINT_TABLE_PROP_NUM_OF_COLUMNS, num_of_columns,
                        NULL);
}

gboolean table_add_entry(PrintTable *tb, int num, ...)
{
    va_list argptr;
    GList *new_entry = NULL;
    const gchar *str;
    int i;

    if (num != tb->priv->num_of_columns) {
        fprintf(stderr, "Error: number not matched!\n");
        return FALSE;
    }

    va_start(argptr, num);
    for (i = 0; i < num; i++) {
        str = va_arg(argptr, const char *);
        new_entry = g_list_append(new_entry, g_strdup(str));

        /* Update length */
        if (tb->priv->columns_lengths[i] < strlen(str))
            tb->priv->columns_lengths[i] = strlen(str);
    }
    va_end(argptr);

    /* Insert to entries */
    tb->priv->entries = g_list_append(tb->priv->entries, new_entry);

    return TRUE;
}

void table_print(PrintTable *tb)
{
    GList *i, *j;
    guint column;
    gchar *format_str;

    for (i = tb->priv->entries; i != NULL; i = i->next) {
        column = 0;
        for (j = i->data; j != NULL; j = j->next) {
            /* Generate format string by length */
            format_str = g_strdup_printf("%%%ds ", tb->priv->columns_lengths[column]);
            g_print(format_str, (gchar *) j->data);
            g_free(format_str);
            column++;
        }
        g_print("\n");
    }
}
