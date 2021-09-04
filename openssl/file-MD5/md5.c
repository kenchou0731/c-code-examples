#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

#include "md5.h"

int print_MD5(unsigned char *md5) {
	int i;

	for(i = 0; i < 16; i++){
		printf("%02x", md5[i]);
	}
	printf("\n");

	return 0;
}

unsigned char *get_file_MD5(const char *filename) {
	MD5_CTX ctx;
	char buffer[1024];
	int len = 0;
	FILE *fp = NULL;
	unsigned char *md5;

	md5 = malloc(16 * sizeof(char));

	fp = fopen(filename,"rb");
	if (fp == NULL) {
		fprintf(stderr, "Can't open file\n");
		return NULL;
	}

	MD5_Init(&ctx);
	while ((len = fread(buffer, 1, 1024, fp)) > 0) {
		MD5_Update(&ctx, buffer, len);
		memset(buffer, 0, sizeof(buffer));
	}

	MD5_Final(md5, &ctx);
	return md5;
}

int compare_MD5(unsigned char *c1, unsigned char *c2) {
	return strncmp(c1, c2, 16);
}
