CC = gcc
CFLAGS = -g -Wall -Wpedantic -Wno-padded \
	$(shell pkg-config --cflags glib-2.0)
LDFLAGS = \
	$(shell pkg-config --libs glib-2.0)

all: test_read_g_key_file test_write_g_key_file

test_read_g_key_file: test_read_g_key_file.o
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

test_write_g_key_file: test_write_g_key_file.o
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f test_read_g_key_file test_write_g_key_file *.o
