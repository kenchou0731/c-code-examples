#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t num_read;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return 2;
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		perror(argv[1]);
		return 1;
	}

	while ((num_read = getline(&line, &len, fp)) != -1) {
		printf("Read length: %zu\n", num_read);
		printf("%s", line);
	}
	printf("\n");

	fclose(fp);
	if (line)
		free(line);

	return 0;
}