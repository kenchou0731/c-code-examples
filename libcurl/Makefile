CC = gcc
CFLAGS = -g -Wall -Wpedantic -Wno-padded \
	$(shell pkg-config --cflags libcurl)
LDFLAGS = \
	$(shell pkg-config --libs libcurl)

all: simple_get

simple_get: simple_get.o
	$(CC) $(CFLAGS) $(LDFLAGS) simple_get.o -o simple_get

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f simple_get *.o