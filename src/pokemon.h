#ifndef _POKEMON_H_
#define _POKEMON_H_

#include "qr.h"

#include "stdio.h"

#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long

typedef struct pgl_pokeparam_data
{
  int Key;
  char HyperTrainingFlags;
  char field_5;
  char field_6;
  char field_7;
  unsigned char PPUps[4];
  int IvFlags;
  int field_10;
  __int16 MonsNo;
  __int16 HoldItem;
  __int16 Moves[4];
  char field_20;
  unsigned char AbilityFlags;
  char Nature;
  char EncounterFlags; //Stored as: Bit 0: Fateful Encounter, Bit 1: Female, Bit 2: Genderless, Bits 3-7: Form Data.
  unsigned char EffortHp;
  unsigned char EffortAtk;
  unsigned char EffortDef;
  unsigned char EffortSpeed;
  unsigned char EffortSpAtk;
  unsigned char EffortSpDef;
  char field_2A;
  char Familiarity;
  char Pokeball;
  char Level;
  char CassetteVersion;
  char LangId;
} pokemon;

typedef struct {
} pm_team;

pokemon* initTeamWithQR(qr_dec_t* qr);
pokemon* initPMWithQR(u8* raw);

int isPM(pokemon* pm);

void printTeam(pokemon* pm);
void printPM(pokemon* pm);
void printPMIV(int ivflags);
void printPMHT(int htflags);

int getHPType(int ivflags);

#endif //_POKEMON_H_
