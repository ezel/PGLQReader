#ifndef _FDECRYPT_H_
#define _FDECRYPT_H_

#include <openssl/aes.h>
#include <stdint.h>

//using std::uint8_t;
//using std::uint64_t;

typedef uint8_t u8;

typedef struct
{
    unsigned char ivec[AES_BLOCK_SIZE];
    unsigned int num;
    unsigned char ecount[AES_BLOCK_SIZE];
} ctr_state;

void init_ctr(ctr_state *state, const unsigned char iv[16]);
void decrypt_data(const u8* src, u8* dst, unsigned int src_len, const u8* iv);

#endif //_FDECRYPT_H_
