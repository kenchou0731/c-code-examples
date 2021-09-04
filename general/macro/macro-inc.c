#include <stdio.h>

#define QWE(...) QWE_ ## __VA_ARGS__ ## _x
#define QWE_1_x 1
#define QWE_2_x 2
#define QWE_3_x 3
#define QWE_4_x 4

int main(void) {
	printf("%d\n", QWE(1));
	printf("%d\n", QWE(2));
	printf("%d\n", QWE(3));
	printf("%d\n", QWE(4));
	return 0;
}

