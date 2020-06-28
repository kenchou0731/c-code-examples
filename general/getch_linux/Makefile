CC = gcc
CFLAGS = -g -Wall
LDFLAGS = 

all: getch_linux

getch_linux: getch_linux.o
	$(CC) $(CFLAGS) $(LDFLAGS) getch_linux.o -o getch_linux

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f getch_linux *.o
