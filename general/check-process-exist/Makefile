CC = gcc
CFLAGS = -g -Wall
LDFLAGS = 

all: check-process-exist

check-process-exist: check-process-exist.o
	$(CC) $(CFLAGS) $(LDFLAGS) check-process-exist.o -o check-process-exist

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f check-process-exist *.o
