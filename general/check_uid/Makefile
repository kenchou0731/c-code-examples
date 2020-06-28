CC = gcc
CFLAGS = -g -Wall
LDFLAGS = 

all: check_uid

check_uid: check_uid.o
	$(CC) $(CFLAGS) $(LDFLAGS) check_uid.o -o check_uid

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f check_uid *.o
