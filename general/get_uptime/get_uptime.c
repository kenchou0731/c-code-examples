#include <stdio.h>
#include <time.h>

int main(void) {
	struct timespec t;

	clock_gettime(CLOCK_MONOTONIC, &t);
	printf("%llu.%llu",
		(unsigned long long) t.tv_sec,
		(unsigned long long) t.tv_nsec / 1000000);
	return 0;
}
