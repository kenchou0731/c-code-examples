CC = gcc
CFLAGS = -g -Wall
LDFLAGS = 

all: va_list

va_list: va_list.o
	$(CC) $(CFLAGS) $(LDFLAGS) va_list.o -o va_list

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f va_list *.o
