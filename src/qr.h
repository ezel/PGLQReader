#ifndef _QR_H_
#define _QR_H_

#include <stdint.h>
#include <stdlib.h>

//using std::uint8_t;
//using std::uint64_t;

typedef uint8_t u8;
typedef uint64_t u64;

// raw data
typedef struct
{
  u8 data[0x18E];
  u8 memesig[0x60];
} qr_meme_t;

// raw data after memecrypto
typedef struct
{
  u8 metadata_flags[0x8];
  u8 random_ctr_for_aes[0x10];
  u8 aes_ctr_encrypted_data[0x1CE];
  u8 sha1_of_preceding[0x8];
} qr_t;

// raw team data
typedef struct
{
  u8 metadata_flags[0x8];
  u8 random_ctr_for_Aes[0x10];
  u8 pokemon_1[0x30];
  u8 pokemon_2[0x30];
  u8 pokemon_3[0x30];
  u8 pokemon_4[0x30];
  u8 pokemon_5[0x30];
  u8 pokemon_6[0x30];
  u64 game_sync_id;
  u8 unknown_data[0xA6];
  u8 sha1_of_preceding[0x8];
} qr_dec_t;

qr_meme_t* initWithPng(char* fpath);
qr_t* memedecryptRawQR(unsigned char* qrdata);

qr_dec_t* decryptoQR(qr_t* source);
#endif //_QR_H_
