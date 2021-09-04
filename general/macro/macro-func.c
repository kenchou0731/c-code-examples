#include <stdio.h>

#define ABC(n) \
	void asd##n() { \
		printf("hello %d\n", n); \
	}

ABC(0)
ABC(1)
ABC(2)

int main(void) {
	asd0();
	asd1();
	asd2();

	return 0;
}
