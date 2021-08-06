CC = gcc
CFLAGS = -g -Wall
LDFLAGS = 

all: base64_enc

base64_enc: base64_enc.o
	$(CC) $(CFLAGS) $(LDFLAGS) base64_enc.o -o base64_enc

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f base64_enc *.o
