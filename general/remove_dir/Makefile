CC = gcc
CFLAGS = -g -Wall
LDFLAGS = 

all: main

main: main.o
	$(CC) $(CFLAGS) $(LDFLAGS) main.o -o main

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f main *.o
