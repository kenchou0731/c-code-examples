CC = gcc
CFLAGS = -g -Wall
LDFLAGS = 

all: monitor_mount_table

monitor_mount_table: monitor_mount_table.o
	$(CC) $(CFLAGS) $(LDFLAGS) monitor_mount_table.o -o monitor_mount_table

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f monitor_mount_table *.o
