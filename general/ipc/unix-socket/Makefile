CC = gcc
CFLAGS = -g -Wall
LDFLAGS = 

all: server client

server: server.o
	$(CC) $(CFLAGS) $(LDFLAGS) server.o -o server

client: client.o
	$(CC) $(CFLAGS) $(LDFLAGS) client.o -o client

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f server client *.o
