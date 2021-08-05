#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>

int main(void) {
	struct pollfd pfd;

	pfd.fd = open("/proc/mounts", O_RDONLY, 0);
	if (pfd.fd < 0) {
		perror("open");
		return 1;
	}
	pfd.events = POLLERR | POLLPRI;
	pfd.revents = 0;
	while (poll(&pfd, 1, 5) >= 0) {
		if (pfd.revents & POLLERR) {
			printf("File /proc/mounts changed.\n");
		}
		pfd.revents = 0;
	}

	close(pfd.fd);
	return 0;
}
