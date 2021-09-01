#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	DIR *dir;
	struct dirent *ptr;

	dir = opendir(argv[1]);
	while ((ptr = readdir(dir)) != NULL) {
		printf("%s\n", ptr->d_name);
	}
	closedir(dir);

	return 0;
}
