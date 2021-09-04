CC = gcc
CFLAGS = -g -Wall
LDFLAGS = 

all: msgtool

msgtool: msgtool.o
	$(CC) $(CFLAGS) $(LDFLAGS) msgtool.o -o msgtool

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f msgtool *.o
