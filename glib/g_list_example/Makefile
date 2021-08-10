CC = gcc
CFLAGS = -g -Wall -Wpedantic -Wno-padded \
	$(shell pkg-config --cflags glib-2.0)
LDFLAGS = \
	$(shell pkg-config --libs glib-2.0)

all: test_g_list list_remove_issue

test_g_list: test_g_list.o
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

list_remove_issue: list_remove_issue.o
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f test_g_list list_remove_issue *.o
