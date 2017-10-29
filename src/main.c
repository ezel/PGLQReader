/**
 * PGLQRReader - A simple tool to decode the qr from PGL QR rental team, written in C
 */

#include <stdio.h>
#include <string.h>

#include "quirc.h"
#include <jpeglib.h>
#include "dbgutil.h"

#include "qr.h"
#include "pokemon.h"

void dumpRaw(unsigned char* p, int maxSize);
int decode_qr(const char* path, unsigned char* output);

static struct quirc *decoder;

int main(int argc, char **argv) {
  if (argc<2) {
    puts("need qr image!");
    return 1;
  }

  //unsigned char* ZXingQR = step1_3;
  //dumpRaw(ZXingQR, 507);
  //qr_dec_t* qr = initWithZXingQR(ZXingQR);

  unsigned char inQR[504];
  int qr_len = decode_qr(argv[1], inQR);
  //dumpRaw(inQR, 507);

  qr_dec_t* qr = initWithquircQR(inQR);
  pokemon* team = initTeamWithQR(qr);

  printf("--------\n");
  printTeam(team);

  free(team);
  free(qr);
  return 0;
}

// make sure the output has enough length
int decode_qr(const char* path, unsigned char* output) {
  // init image path
  //const char* path = argv[1];
  const char *filename, *ext;
  int len = strlen(path);
  while (len >= 0 && path[len] != '/')
    len--;
  filename = path + len + 1;

  len = strlen(filename);
  while (len >= 0 && filename[len] != '.')
    len--;
  ext = filename + len + 1;

  // read image
  int (*loader)(struct quirc *, const char *);
  if (strcasecmp(ext, "jpg") == 0 || strcasecmp(ext, "jpeg") == 0)
    loader = load_jpeg;
  else if (strcasecmp(ext, "png") == 0)
    loader = load_png;
  else {
    fprintf(stderr, "%s: need .png or .jpg/.jpeg file.\n", filename);
    return -1;
  }
  // load image
  decoder = quirc_new();
  int ret = loader(decoder, path);

  if (ret < 0) {
    fprintf(stderr, "%s: load failed\n", filename);
    return -1;
  }

  quirc_end(decoder);

  // extract image
  struct quirc_code code;
  quirc_extract(decoder, 0, &code);

  struct quirc_data data;
  quirc_decode_error_t err = quirc_decode(&code, &data);

  if (err) {
    printf("  ERROR: %s\n\n",
           quirc_strerror(err));
  } else {
    printf("Decode QR successful, length:%d \n", data.payload_len);
  }
  memcpy(output, &data.payload, data.payload_len);

  quirc_destroy(decoder);

  return data.payload_len;
}

void dumpRaw(unsigned char* p, int maxSize) {
  for (int i = 0; i < 0x20; i++)
    {
      if (i*0x10 >= maxSize) break;
      for (int j = 0; j < 0x10; j++) {
        if (i*0x10+j >= maxSize) break;
        printf("%03d ", p[i*0x10+j]);
        //printf("%02x ", p[i*0x10+j]);
      }
      printf("\n");
    }
}
