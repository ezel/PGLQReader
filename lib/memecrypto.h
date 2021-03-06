#ifndef _MEMECRYPTO_H_
#define _MEMECRYPTO_H_

#include <string.h>
#include <openssl/aes.h>
#include <openssl/bn.h>
#include <openssl/rsa.h>
#include <openssl/sha.h>

#define MEME_LEN 0x60

void memecrypto_aes_encrypt(unsigned char *buf, unsigned char *output, unsigned char *key);
void memecrypto_aes_decrypt(unsigned char *buf, unsigned char *output, unsigned char *key);

int memecrypto_sign(unsigned char *input, unsigned char *output, int len);
int memecrypto_verify(unsigned char *input, unsigned char *output, int len);

int memecrypto_verify_new(unsigned char *input, unsigned char *output, int len);
#endif //_MEMECRYPTO_H_
