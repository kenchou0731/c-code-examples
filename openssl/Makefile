CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -lcrypto

all: hmac_sha256

hmac_sha256: hmac_sha256.o
	$(CC) $(CFLAGS) $(LDFLAGS) hmac_sha256.o -o hmac_sha256

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f hmac_sha256 *.o
