CC = gcc
CFLAGS = -g -Wall -Wpedantic -Wno-padded \
	$(shell pkg-config --cflags glib-2.0)
LDFLAGS = \
	$(shell pkg-config --libs glib-2.0)

all: test_g_strsplit

test_g_strsplit: test_g_strsplit.o
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f test_g_strsplit *.o
