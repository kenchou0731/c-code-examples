CC = gcc
CFLAGS = -g -Wall
LDFLAGS = 

all: pipe-ex

pipe-ex: pipe-ex.o
	$(CC) $(CFLAGS) $(LDFLAGS) pipe-ex.o -o pipe-ex

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f pipe-ex *.o
