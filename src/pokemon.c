#include "pokemon.h"
#include "pmdata.h"

pokemon* initTeamWithQR(qr_dec_t* qr) {
  pokemon* res = malloc(sizeof(pokemon)*6);
  memcpy(res, (unsigned char*)qr->pokemon_1, 0x30*6);
  return res;
}

pokemon* initPMWithQR(u8* raw) {
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
  int formid = pm->EncounterFlags >> 3;
  printf("Monster: #%d %s @ %s\n", pm->MonsNo, getPM_MonsName(pm->MonsNo, formid), getPM_ItemName(pm->HoldItem));
  //printf("FormID: %d\n", formid);
  printf("Ability: %s\n", getPM_AbilityNameByFlag(pm->MonsNo, formid, pm->AbilityFlags));
  //printf("AbilityFlags: %d\n", pm->AbilityFlags);
  printf("Level: %d\n", pm->Level);
  //printf("HoldItem: %s\n", getPM_ItemName(pm->HoldItem));
  printf("Nature: %s\n", getPM_NatureName(pm->Nature));
  printPMIV(pm->IvFlags);
  printPMHT(pm->HyperTrainingFlags);
  printf("EVs:%d/%d/%d/%d/%d/%d\n", pm->EffortHp, pm->EffortAtk, pm->EffortDef, pm->EffortSpAtk, pm->EffortSpDef, pm->EffortSpeed);

  printf("Move: %s / %s / %s / %s \n", getPM_MoveName(pm->Moves[0]), getPM_MoveName(pm->Moves[1]), getPM_MoveName(pm->Moves[2]), getPM_MoveName(pm->Moves[3]));
  //for (int i=0;i<4; i++) {  printf("Move %i: %s\n", i+1, getPM_MoveName(pm->Moves[i])); }
  printf("PPUps: %d/%d/%d/%d\n", pm->PPUps[0], pm->PPUps[1], pm->PPUps[2], pm->PPUps[3]);
  printf("HPType: %s\n", getPM_TypeName(getHPType(pm->IvFlags)));
  //printf("Familiarity: %d\n", pm->Familiarity);
}

void printPMIV(int IVFlags) {
  int IVTemp[6] = {0};
  for (int i=0; i<6; i++) { // hp atk def spd satk sdef
    IVTemp[i] = ((int)IVFlags>>(i*5)) & 0x1F;
    printf("IV[%d]:%d ", i, IVTemp[i]);
  }
  printf("\n");
}

void printPMHT(int HTFlags) {
  int HTTemp[6] = {0};
  for (int i=0; i<6; i++) {
    HTTemp[i] = HTFlags>>(i*1) & 0x01;
    printf("HT[%d]:%d ", i, HTTemp[i]);
  }
  printf("\n");
}

int getHPType(int IVFlags) {
  int IVTemp[6] = {0};
  for (int i=0; i<6; i++) // hp atk def spd satk sdef
    IVTemp[i] = ((int)IVFlags>>(i*5)) & 0x1F;
  int type = IVTemp[0] % 2 + (IVTemp[1] % 2) * 2 + (IVTemp[2] % 2) * 4 + (IVTemp[3] % 2) * 8 + (IVTemp[4] % 2) * 16 + (IVTemp[5] % 2) * 32;
  type = (type * 15) / 63;
  return type;
}
