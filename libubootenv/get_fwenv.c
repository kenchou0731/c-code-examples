#include <stdio.h>
#include <stdlib.h>
#include <libuboot.h>

#define LIBUBOOTENV_FWENV "/etc/fw_env.config"

int main(int argc, char *argv[])
{
	struct uboot_ctx *ctx;
	const char *envval;

	if (libuboot_initialize(&ctx, NULL) < 0) {
		fprintf(stderr, "Cannot initialize environment\n");
		return 1;
	}
	
	if (libuboot_read_config(ctx, LIBUBOOTENV_FWENV) < 0) {
		fprintf(stderr, "Configuration file %s wrong or corrupted\n", LIBUBOOTENV_FWENV);
		libuboot_exit(ctx);
		return 1;
	}

	if (libuboot_open(ctx) < 0) {
		fprintf(stderr, "Cannot read environment, using default\n");
		libuboot_exit(ctx);
		return 1;
	}
	
	envval = libuboot_get_env(ctx, argv[1]);
	printf("%s=%s\n", argv[1], envval ? envval : "");

	libuboot_close(ctx);
	libuboot_exit(ctx);
	return 0;
}
