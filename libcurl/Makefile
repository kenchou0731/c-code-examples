CC = gcc
CFLAGS = -g -Wall -Wpedantic -Wno-padded \
	$(shell pkg-config --cflags libcurl)
LDFLAGS = \
	$(shell pkg-config --libs libcurl)

all: simple_get simple_post get_in_memory

simple_get: simple_get.o
	$(CC) $(CFLAGS) $(LDFLAGS) simple_get.o -o simple_get

simple_post: simple_post.o
	$(CC) $(CFLAGS) $(LDFLAGS) simple_post.o -o simple_post

get_in_memory: get_in_memory.o
	$(CC) $(CFLAGS) $(LDFLAGS) get_in_memory.o -o get_in_memory

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f simple_get simple_post get_in_memory *.o