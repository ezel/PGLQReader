#include "pokemon.h"

#include "string.h"
#include "stdio.h"

pokemon* initListWithQR(qr_dec_t* qr) {
  pokemon* res = malloc(sizeof(pokemon)*6);
  memcpy(res, (unsigned char*)qr->pokemon_1, 0x30*6);
  return res;
}

pokemon* initOneWithQR(u8* raw) {
  pokemon* res = malloc(sizeof(pokemon));
  memcpy(res, raw, 0x30);
  return res;
}

int isPM(pokemon* pm) {
  if (pm->MonsNo < 0 || pm->MonsNo > 900)
    return 0;
  else return 1;
}

void printTeam(pokemon* team) {
  for (int i=0; i<6; i++) {
    if (isPM(team+i)) { printPM(team+i); }
    else printf("Not a pm");
    printf("\n");
  }
}

void printPM(pokemon* pm) {
  printf("Monster: #%i\n", pm->MonsNo);
  printf("AbilityFlags: #%c\n", pm->AbilityFlags);
  printf("Nature: #%c\n", pm->Nature);
  printf("%c/%c/%c/%c/%c/%c\n", pm->EffortHp, pm->EffortAtk, pm->EffortDef, pm->EffortSpAtk, pm->EffortSpDef, pm->EffortSpeed);
  printf("Level: #%c\n", pm->Level);
  printf("LangId: #%i\n", pm->LangId);
}
