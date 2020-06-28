CC = gcc
CFLAGS = -g -Wall
LDFLAGS = 

all: get_uptime

get_uptime: get_uptime.o
	$(CC) $(CFLAGS) $(LDFLAGS) get_uptime.o -o get_uptime

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f get_uptime *.o
