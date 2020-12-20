#include <stdio.h>
#include <memory.h>
#include <string.h>

#include "aes.h"

int main(int argc, char * argv[])
{
	uint8_t in[16];
	uint8_t encrypted[16];
	uint8_t decrypted[16];
	uint8_t * expanded_key;
	// 256 bit key 
	const uint8_t key[] = {
		0x00, 0x01, 0x02, 0x03,
		0x04, 0x05, 0x06, 0x07,
		0x08, 0x09, 0x0a, 0x0b,
		0x0c, 0x0d, 0x0e, 0x0f,
		0x10, 0x11, 0x12, 0x13,
		0x14, 0x15, 0x16, 0x17,
		0x18, 0x19, 0x1a, 0x1b,
		0x1c, 0x1d, 0x1e, 0x1f,
	};

	if (argc != 2)
	{
		printf("Usage: test.exe  input_string");
		return 0;
	}
	memset(in, 0, 16);
	strncpy(in, argv[1], 16);

	expanded_key = aes_init(sizeof(key));
	aes_key_expansion(key, expanded_key);

	printf("Plaintext message:\n");
	for (int i = 0; i < 16; i++) {
		printf("%02x", in[i]);
	}
	printf("\n");

	aes_cipher(in, encrypted, expanded_key);

	printf("Ciphered message:\n");
	for (int i = 0; i < 16; i++) {
		printf("%02x", encrypted[i]);
	}
	printf("\n");

	aes_inv_cipher(encrypted, decrypted, expanded_key);
	printf("Decoded message:\n");
	for (int i = 0; i < 16; i++) {
		printf("%02x,", decrypted[i]);
	}
	printf("\n");

	free(expanded_key);
	return 0;
}