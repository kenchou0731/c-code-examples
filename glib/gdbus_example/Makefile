CC = gcc
CFLAGS = -g -Wall -Wpedantic -Wno-padded \
	$(shell pkg-config --cflags glib-2.0 gio-2.0 gio-unix-2.0)
LDFLAGS = \
	$(shell pkg-config --libs glib-2.0 gio-2.0 gio-unix-2.0)

all: server cli

server: myobj.o server.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ myobj.o server.o

cli: myobj.o cli.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ myobj.o cli.o

myobj.c myobj.h: example.ken.testdbus.MyObject.xml
	gdbus-codegen \
		--interface-prefix example.ken.testdbus \
		--c-namespace GDBusKenTest \
		--generate-c-code myobj \
		example.ken.testdbus.MyObject.xml

%.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

install:
	cp example.ken.testdbus.conf /etc/dbus-1/system.d/

clean:
	rm -f server cli *.o
