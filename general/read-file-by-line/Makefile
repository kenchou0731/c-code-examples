CC = gcc
CFLAGS = -g -Wall
LDFLAGS = 

all: read-file-by-line

read-file-by-line: read-file-by-line.o
	$(CC) $(CFLAGS) $(LDFLAGS) read-file-by-line.o -o read-file-by-line

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f read-file-by-line *.o
