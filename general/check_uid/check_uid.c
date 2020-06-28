#include <unistd.h>
#include <stdio.h>

int main(void)
{
	uid_t uid, euid;

	uid = getuid();
	euid = geteuid();
	if (uid < 0 || uid != euid) {
		printf("Not root\n");
	} else {
		printf("Root\n");
	}
	return 0;
}
