CC = gcc
CFLAGS = -g -Wall -Wpedantic -Wno-padded \
	$(shell pkg-config --cflags libcjson)
LDFLAGS = \
	$(shell pkg-config --libs libcjson)

all: parse_ex build_ex

parse_ex: parse_ex.o
	$(CC) $(CFLAGS) $(LDFLAGS) parse_ex.o -o parse_ex

build_ex: build_ex.o
	$(CC) $(CFLAGS) $(LDFLAGS) build_ex.o -o build_ex

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f parse_ex build_ex *.o