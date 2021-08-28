CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -lm

all: main

main: main.o point.o labeledPoint.o
	$(CC) $(CFLAGS) $(LDFLAGS) main.o point.o labeledPoint.o -o main

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f main *.o
