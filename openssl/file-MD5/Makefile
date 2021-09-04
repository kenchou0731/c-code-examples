CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -lcrypto

all: main

main: main.o md5.o
	$(CC) $(CFLAGS) $(LDFLAGS) main.o md5.o -o main

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f main *.o
