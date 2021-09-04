CC = gcc
CFLAGS = -g -Wall
LDFLAGS = 

all: popen-ex

popen-ex: popen-ex.o
	$(CC) $(CFLAGS) $(LDFLAGS) popen-ex.o -o popen-ex

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f popen-ex *.o
