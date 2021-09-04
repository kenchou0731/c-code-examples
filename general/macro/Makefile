CC = gcc
CFLAGS = -g -Wall
LDFLAGS = 

all: macro-inc macro-func

macro-inc: macro-inc.o
	$(CC) $(CFLAGS) $(LDFLAGS) macro-inc.o -o macro-inc

macro-func: macro-func.o
	$(CC) $(CFLAGS) $(LDFLAGS) macro-func.o -o macro-func

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f macro-inc macro-func *.o
