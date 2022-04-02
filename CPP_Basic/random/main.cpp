#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void) {
	int x;

	srand(time(NULL));
	x = rand();
	std::cout << "x = " << x << std::endl;
	return 0;
}
