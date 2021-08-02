#include <glib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
	    return 1;

    g_print("%s\n", g_getenv(argv[1]));

    return 0;
}
