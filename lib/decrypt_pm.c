#include "decrypt_pm.h"
#include <string.h>

void init_ctr(ctr_state *state, const unsigned char iv[16])
{
  state->num = 0;
  memset(state->ecount, 0, 16);

  memcpy(state->ivec, iv, 16);
  //memset(state->ivec + 8, 0, 8);
}

void decrypt_pm(const u8* src, u8* dst, unsigned int src_len, const u8* iv)
{
  //const unsigned char* enc_key = (const unsigned char*)"0F8E2F405EAE51504EDBA7B4E297005B";
  const unsigned char enc_key[] = {0x0F, 0x8E, 0x2F, 0x40, 0x5E, 0xAE, 0x51, 0x50,
                                  0x4E, 0xDB, 0xA7, 0xB4, 0xE2, 0x97, 0x00, 0x5B };
  ctr_state state;
  AES_KEY aes_key;
  AES_set_encrypt_key(enc_key, 128, &aes_key);
  init_ctr(&state, iv);
  AES_ctr128_encrypt(src, dst, src_len, &aes_key, state.ivec, state.ecount, &state.num);
}
