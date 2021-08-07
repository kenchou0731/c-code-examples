CC = gcc
CFLAGS = -g -Wall
LDFLAGS = 

all: encapsulation

encapsulation: encapsulation.o
	$(CC) $(CFLAGS) $(LDFLAGS) encapsulation.o -o encapsulation

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f encapsulation *.o
