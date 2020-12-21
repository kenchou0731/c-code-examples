CC = gcc
CFLAGS = -g -Wall -Wpedantic -Wno-padded \
	$(shell pkg-config --cflags glib-2.0 gio-2.0 gio-unix-2.0)
LDFLAGS = \
	$(shell pkg-config --libs glib-2.0 gio-2.0 gio-unix-2.0)

all: server cli

server: gen.o gdbus-example-objectmanager-server.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ gen.o gdbus-example-objectmanager-server.o

cli: gen.o gdbus-example-objectmanager-client.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ gen.o gdbus-example-objectmanager-client.o

gen.c gen.h: gdbus-example-objectmanager.xml
	gdbus-codegen \
		--interface-prefix org.gtk.GDBus.Example.ObjectManager. \
		--c-namespace Example \
		--generate-c-code gen \
		--c-generate-object-manager \
		gdbus-example-objectmanager.xml

%.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

clean:
	rm -f server cli *.o
