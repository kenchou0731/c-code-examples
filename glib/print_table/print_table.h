#ifndef PRINT_TABLE_H
#define PRINT_TABLE_H

#include <gio/gio.h>

/*****************************************************************************/

#define G_TYPE_PRINT_TABLE            (print_table_get_type())
#define PRINT_TABLE(obj)              (G_TYPE_CHECK_INSTANCE_CAST((obj), G_TYPE_PRINT_TABLE, PrintTable))
#define PRINT_TABLE_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST((klass),  G_TYPE_PRINT_TABLE, PrintTableClass))
#define G_IS_PRINT_TABLE(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), G_TYPE_PRINT_TABLE))
#define G_IS_PRINT_TABLE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass),  G_TYPE_PRINT_TABLE))
#define PRINT_TABLE_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS((obj),  G_TYPE_PRINT_TABLE, PrintTableClass))

typedef struct _PrintTable PrintTable;
typedef struct _PrintTableClass PrintTableClass;
typedef struct _PrintTablePrivate PrintTablePrivate;

/* Properties */
#define PRINT_TABLE_PROP_NUM_OF_COLUMNS "num-of-columns"

struct _PrintTable {
    GObject parent;
    PrintTablePrivate *priv;
};

struct _PrintTableClass {
    GObjectClass parent;
};

GType print_table_get_type(void);

/*****************************************************************************/

PrintTable *table_new(guint num_of_columns);
gboolean table_add_entry(PrintTable *tb, int num, ...);
void table_print(PrintTable *tb);

#endif /* PRINT_TABLE_H */
