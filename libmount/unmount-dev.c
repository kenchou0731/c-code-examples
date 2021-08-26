#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <libmount.h>

int main(int argc, char *argv[]) {
	struct libmnt_context *cxt;
	int rc;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <device>\n", argv[0]);
		return 2;
	}

	cxt = mnt_new_context();
	if (!cxt) {
		fprintf(stderr, "Error creating new mount context\n");
		return 1;
	}

	mnt_context_set_source(cxt, argv[1]);

	rc = mnt_context_umount(cxt);
	if (mnt_context_helper_executed(cxt)) {
		return mnt_context_get_helper_status(cxt);
	}

	if (rc == 0 && mnt_context_get_status(cxt) == 1) {
		mnt_free_context(cxt);
		return 0;
	}
	mnt_free_context(cxt);
	return 1;
}
