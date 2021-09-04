#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>

int is_proc_exist(int pid) {
	int ret;

	ret = kill(pid, 0);
	if (ret == -1) {
		if (errno == ESRCH)
			return 0;
	}
	return 1;
}

int main(int argc, char *argv[]) {
	int pid;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
		return 2;
	}

	pid = atoi(argv[1]);
	if (pid == 0) {
		fprintf(stderr, "No process 0\n");
		return 1;
	}

	if (is_proc_exist(pid))
		printf("Process %d exists\n", pid);
	else
		printf("Process %d doesn't exist\n", pid);

	return 0;
}
