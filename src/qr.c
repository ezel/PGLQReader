#include <string.h>

#include "qr.h"
#include "memecrypto.h"
#include "fdecrypt.h"
/*
qr_meme_t* initWithPng(char* fpath) {
  return 0;
}
*/
qr_meme_t* initWithArray(unsigned char* data) {
  qr_meme_t* res = malloc(sizeof(qr_meme_t));
  memcpy(res, data, 0x1EE);
  return res;
}

qr_t* memedecryptoRawQR(qr_meme_t* source) {
  // qr_t = memecrypto_verify(qr_meme_t);
  qr_t* output = malloc(sizeof(qr_t));
  if (memecrypto_verify((unsigned char*)source, (unsigned char*)output, 0x1EE)) {
    return NULL;
  } else {
    return output;
  }
}

qr_dec_t* decryptoQR(qr_t* source) {
  qr_dec_t* res = malloc(sizeof(qr_dec_t));
  int len = 0x1CE;
  u8 sourceData[0x1CE];
  u8 recovered[128];
  unsigned char iv[AES_BLOCK_SIZE];

  // init qr_dec_t, sourceData, and aes iv
  memcpy(res, source, sizeof(qr_dec_t));
  memcpy(sourceData, source->aes_ctr_encrypted_data, len);
  memset(recovered, 0, sizeof(recovered));
  /* source->aes_ctr_encrypted_data is  encrypted in aes-ctr 128 */
  /* with the key 0F8E2F405EAE51504EDBA7B4E297005B  and iv: source->random_ctr_for_aes */
  memcpy(iv, source->random_ctr_for_aes, AES_BLOCK_SIZE);

  decrypt_data(sourceData, recovered, len, iv);
  // save result
  memcpy((u8*)res+0x18, recovered, len);
  return res;
}

void printRawOct(unsigned char* r, int len) {
  if (r) {
    for (int i=0; i<len; i++) {
      printf("%02X ", r[i]);
    }
    printf("\n");
  } else printf("null\n");
}

void printRawQr(unsigned char* r) {
  if (r) {
    for (int i=0; i<0x1F; i++) {
      for (int j=0; j<0x10; j++) {
        printf("%02X ", r[0x10*i+j]);
        //if (0x10*i+j > 0x1ED) break;
      }
      printf("\n");
    }
  } else printf("null\n");
}
