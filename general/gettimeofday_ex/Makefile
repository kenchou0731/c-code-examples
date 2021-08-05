CC = gcc
CFLAGS = -g -Wall
LDFLAGS = 

all: gettimeofday1 gettimeofday2

gettimeofday1: gettimeofday1.o
	$(CC) $(CFLAGS) $(LDFLAGS) gettimeofday1.o -o gettimeofday1

gettimeofday2: gettimeofday2.o
	$(CC) $(CFLAGS) $(LDFLAGS) gettimeofday2.o -o gettimeofday2

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f gettimeofday1 gettimeofday2 *.o
