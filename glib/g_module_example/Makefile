CC = gcc
CFLAGS = -g -Wall -Wpedantic -Wno-padded \
	$(shell pkg-config --cflags glib-2.0 gmodule-2.0)
LDFLAGS = \
	$(shell pkg-config --libs glib-2.0 gmodule-2.0)

all: test_g_module m1 m2

test_g_module: test_g_module.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_g_module.o -o test_g_module

m1: module1.o
	$(CC) -shared -Wl,-soname,module1.so -o module1.so module1.o

m2: module2.o
	$(CC) -shared -Wl,-soname,module2.so -o module2.so module2.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f test_g_module *.o

test:
	@mkdir -p /tmp/test_g_module/
	@cp test_g_module module1.so module2.so /tmp/test_g_module/
	@/tmp/test_g_module/test_g_module /tmp/test_g_module/module1.so
	@/tmp/test_g_module/test_g_module /tmp/test_g_module/module2.so
