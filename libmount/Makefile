CC = gcc
CFLAGS = -g -Wall -Wpedantic -Wno-padded \
	$(shell pkg-config --cflags mount)
LDFLAGS = \
	$(shell pkg-config --libs mount)

all: get_mountpoint mount-dev unmount-dev

get_mountpoint: get_mountpoint.o
	$(CC) $(CFLAGS) $(LDFLAGS) get_mountpoint.o -o get_mountpoint

mount-dev: mount-dev.o
	$(CC) $(CFLAGS) $(LDFLAGS) mount-dev.o -o mount-dev

unmount-dev: unmount-dev.o
	$(CC) $(CFLAGS) $(LDFLAGS) unmount-dev.o -o unmount-dev

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f get_mountpoint mount-dev unmount-dev *.o
