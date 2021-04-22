CC = gcc
CFLAGS = -g -Wall -Wpedantic -Wno-padded \
	$(shell pkg-config --cflags glib-2.0 gobject-2.0)
LDFLAGS = \
	$(shell pkg-config --libs glib-2.0 gobject-2.0)

all: test_table

test_table: main.o print_table.o
	$(CC) $(CFLAGS) $(LDFLAGS) main.o print_table.o -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f test_table *.o
