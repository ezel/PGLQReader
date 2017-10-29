#include "qr.h"
#include "memecrypto.h"
#include "decrypt_pm.h"

#include <openssl/aes.h>
/*
qr_meme_t* initWithPng(char* fpath) {
  return 0;
}
*/
qr_dec_t* initWithZXingQR(unsigned char* qrdata) {
  qr_dec_t* res;
  shiftArray(qrdata);
  qr_t* memedec_qr = memedecryptShiftedQR((unsigned char*)qrdata+3);
  if (memedec_qr != NULL)
    res = decryptoQR(memedec_qr);
  else res = NULL;
  free(memedec_qr);
  return res;
}

qr_t* memedecryptShiftedQR(unsigned char* qr) {
  unsigned char output[504];
  qr_t* raw_qr = malloc(sizeof(qr_t));
  if (memecrypto_verify_new((unsigned char*)qr, (unsigned char*)&output, 504)) {
    memcpy(raw_qr, output, sizeof(qr_t));
    return raw_qr;
  } else {
    return NULL;
  }
}

qr_dec_t* decryptoQR(qr_t* source) {
  qr_dec_t* res = malloc(sizeof(qr_dec_t));
  int len = 0x1CE;
  u8 sourceData[0x1CE];
  u8 recovered[0x1C0];
  unsigned char iv[AES_BLOCK_SIZE];

  // init sourceData, and aes iv
  memcpy(sourceData, source->aes_ctr_encrypted_data, len);
  memset(recovered, 0, sizeof(recovered));
  /* source->aes_ctr_encrypted_data is  encrypted in aes-ctr 128 */
  /* with the key 0F8E2F405EAE51504EDBA7B4E297005B  and iv: source->random_ctr_for_aes */
  memcpy(iv, source->random_ctr_for_aes, AES_BLOCK_SIZE);

  decrypt_pm(sourceData, recovered, len, iv);
  // save result
  memcpy(res, source, sizeof(qr_dec_t));
  memcpy((u8*)res+0x18, recovered, len);
  return res;
}

unsigned char* shiftArray(unsigned char* b) {
  unsigned char* array = malloc(507);
  unsigned char lb = 0;
  unsigned char rb = 0;
  for(int i=0;i<507;i++)
    {
      unsigned char B = b[i];
      lb = (B & 0xF0)>>4;
      array[i] = rb << 4 | lb;
      rb = B & 0xF;
    }

  return array;
}
