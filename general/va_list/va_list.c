#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int show(int count, ...) {
	va_list argptr;
	int i;

	va_start(argptr, count);
	for (i = 0; i < count; i++) {
		const char *str = va_arg(argptr, char *);
		printf("%s\n", str);
	}
	va_end(argptr);
	return 0;
}

int main (void) {
	show(3, "test1", "test2", "test3");
	return 0;
}
