CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -lpthread

all: semaphore

semaphore: semaphore.o
	$(CC) $(CFLAGS) $(LDFLAGS) semaphore.o -o semaphore

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f semaphore *.o
