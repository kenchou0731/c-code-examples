CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -lcrypto

all: hmac-sha256

hmac-sha256: hmac-sha256.o
	$(CC) $(CFLAGS) $(LDFLAGS) hmac-sha256.o -o hmac-sha256

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f hmac-sha256 *.o
