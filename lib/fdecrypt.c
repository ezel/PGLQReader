#include "fdecrypt.h"
#include <string.h>

void init_ctr(ctr_state *state, const unsigned char iv[16])
{
  state->num = 0;
  memset(state->ecount, 0, 16);
  memcpy(state->ivec, iv, 16);
}

void decrypt_data(const u8* src, u8* dst, unsigned int src_len, const u8* iv)
{
  const unsigned char* enc_key = (const unsigned char*)"0F8E2F405EAE51504EDBA7B4E297005B";
  ctr_state state;
  AES_KEY key;
  AES_set_encrypt_key(enc_key, 128, &key);

  init_ctr(&state, iv);
  AES_ctr128_encrypt(src, dst, src_len, &key, state.ivec, state.ecount, &state.num);
}
