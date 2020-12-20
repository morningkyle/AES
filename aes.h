/*
 * Advanced Encryption Standard
 * @author Dani Huertas
 * @email huertas.dani@gmail.com
 *
 * Based on the document FIPS PUB 197
 */

#include <stdint.h>
#include <stdlib.h>

// Return a buffer for the expanded key
uint8_t *aes_init(size_t key_size);

// Transform the given key to a expanded key
void aes_key_expansion(const uint8_t *key, uint8_t *expanded);

// Encrypt the input with the expanded key
void aes_cipher(uint8_t *in, uint8_t *out, uint8_t *exkey);

// Decrypt the input with the expanded key
void aes_inv_cipher(uint8_t* in, uint8_t* out, uint8_t* exkey);

