#include <stdio.h>
#include <stdlib.h>

#define COMMAND "ls -l /"

int main(int argc, char *argv[]) {
	FILE *fp;
	char path[1024];
	int st;

	/* Open the command for reading. */
	fp = popen(COMMAND, "r");
	if (fp == NULL) {
		fprintf(stderr, "Failed to run command\n" );
		exit(1);
	}

	/* Read the output a line at a time - output it. */
	while (fgets(path, sizeof(path) - 1, fp) != NULL) {
		printf("| %s", path);
	}

	/* Close */
	st = pclose(fp); 
	if (WIFEXITED(st)) {
		printf("Exit code: %d\n", WEXITSTATUS(st));
	}

	return 0;
}
