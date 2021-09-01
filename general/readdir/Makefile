CC = gcc
CFLAGS = -g -Wall
LDFLAGS = 

all: readdir

readdir: readdir.o
	$(CC) $(CFLAGS) $(LDFLAGS) readdir.o -o readdir

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f readdir *.o
