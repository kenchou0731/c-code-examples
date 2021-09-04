#include <openssl/hmac.h>
#include <string.h>
#include <stdio.h>

unsigned char *key = (unsigned char*) "Hello World";
unsigned char *data = (unsigned char*) "1234567890";
unsigned char *expected = (unsigned char*) "72ddcf10514ac126a371b1a84b41e681e4afee30d3abd11f4104ed9cf96468c4";

int main(void) {
	unsigned char *result;
	static char res_hexstring[64];
	int result_len = 32;
	int i;

	result = HMAC(EVP_sha256(), key, strlen((char *) key), data, strlen((char *) data), NULL, NULL);
	for (i = 0; i < result_len; i++) {
		sprintf(&(res_hexstring[i * 2]), "%02x", result[i]);
	}

	if (strcmp((char *) res_hexstring, (char *) expected) == 0) {
		printf("Got %s\nTest ok\n", res_hexstring);
	} else {
		printf("Got %s\nTest failed", res_hexstring);
	}
	return 0;
}
