#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include <libmount.h>

int main(int argc, char *argv[]) {
	struct libmnt_table *tab;
	struct libmnt_fs *fs;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <device>\n", argv[0]);
		return 2;
	}

	tab = mnt_new_table();
	if (!tab) {
		fprintf(stderr, "Error creating new mount table\n");
		return 1;
	}
	mnt_table_parse_file(tab, "/proc/self/mountinfo");

	fs = mnt_table_find_source(tab, argv[1], MNT_ITER_FORWARD);
	if (fs != NULL) {
		printf("%s\n", mnt_fs_get_target(fs));
		printf("%s\n", mnt_fs_get_fstype(fs));
		mnt_unref_fs(fs);
	}

	mnt_free_table(tab);
	return 0;
}
