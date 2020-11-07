CC = gcc
CFLAGS = -g -Wall -Wpedantic -Wno-padded \
	$(shell pkg-config --cflags libubootenv)
LDFLAGS = \
	$(shell pkg-config --libs libubootenv)

all: get_fwenv

get_fwenv: get_fwenv.o
	$(CC) $(CFLAGS) $(LDFLAGS) get_fwenv.o -o get_fwenv

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f get_fwenv *.o