#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static const char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static char *decoding_table = NULL;
static int mod_table[] = {0, 2, 1};

unsigned char *base64_encode(const unsigned char *data, int input_length, int *output_length) {
	unsigned char *output;
	uint32_t octet_a, octet_b, octet_c, triple;
	int i, j;

	*output_length = 4 * ((input_length + 2) / 3);
	output = malloc(*output_length);
	if (output == NULL)
		return NULL;

	for (i = 0, j = 0; i < input_length;) {
		octet_a = i < input_length ? (unsigned char) data[i++] : 0;
		octet_b = i < input_length ? (unsigned char) data[i++] : 0;
		octet_c = i < input_length ? (unsigned char) data[i++] : 0;
		triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

		output[j++] = base64_table[(triple >> 3 * 6) & 0x3F];
		output[j++] = base64_table[(triple >> 2 * 6) & 0x3F];
		output[j++] = base64_table[(triple >> 1 * 6) & 0x3F];
		output[j++] = base64_table[(triple >> 0 * 6) & 0x3F];
	}

	for (i = 0; i < mod_table[input_length % 3]; i++)
		output[*output_length - 1 - i] = '=';

	return output;
}

static void build_decoding_table() {
	int i;

	decoding_table = malloc(256);
	for (i = 0; i < 64; i++)
		decoding_table[(unsigned char) base64_table[i]] = i;
}

static void base64_cleanup() {
	free(decoding_table);
}

unsigned char *base64_decode(const char *data, size_t input_length, size_t *output_length) {
	if (decoding_table == NULL)
		build_decoding_table();

	if (input_length % 4 != 0)
		return NULL;

	*output_length = input_length / 4 * 3;
	if (data[input_length - 1] == '=') (*output_length)--;
	if (data[input_length - 2] == '=') (*output_length)--;

	unsigned char *decoded_data = malloc(*output_length);
	if (decoded_data == NULL)
		return NULL;

	for (int i = 0, j = 0; i < input_length;) {
		uint32_t sextet_a = data[i] == '=' ? 0 & i++ : decoding_table[(unsigned char) data[i++]];
		uint32_t sextet_b = data[i] == '=' ? 0 & i++ : decoding_table[(unsigned char) data[i++]];
		uint32_t sextet_c = data[i] == '=' ? 0 & i++ : decoding_table[(unsigned char) data[i++]];
		uint32_t sextet_d = data[i] == '=' ? 0 & i++ : decoding_table[(unsigned char) data[i++]];

		uint32_t triple = (sextet_a << 3 * 6)
		+ (sextet_b << 2 * 6)
		+ (sextet_c << 1 * 6)
		+ (sextet_d << 0 * 6);

		if (j < *output_length) decoded_data[j++] = (triple >> 2 * 8) & 0xFF;
		if (j < *output_length) decoded_data[j++] = (triple >> 1 * 8) & 0xFF;
		if (j < *output_length) decoded_data[j++] = (triple >> 0 * 8) & 0xFF;
	}

	return decoded_data;
}


int main(int argc, char *argv[]) {
	int len;

	printf("%s\n", base64_encode((unsigned char *) argv[1], strlen(argv[1]), &len));
	return 0;
}
