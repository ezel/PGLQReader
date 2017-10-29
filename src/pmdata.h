#ifndef _PM_DATA_H_
#define _PM_DATA_H_

#define MAX_TYPE_LEN 9
#define MAX_NATURE_LEN 8
#define MAX_MONS_LEN 15
#define MAX_MOVE_LEN 30
#define MAX_ABILITY_LEN 20
#define MAX_ITEM_LEN 30

#define MONS_FORM_MAX 117
#define MAX_FORM_MONS_LEN 20

const char* getPM_MonsName(int monsid, int formid);
const char* getPM_TypeName(int typeid);
const char* getPM_NatureName(int natureid);
const char* getPM_ItemName(int itemid);
const char* getPM_MoveName(int moveid);
const char* getPM_AbilityNameByFlag(int monsid, int formid, int abflag);

int getKeyByMonsForm(int monsid, int formid);
#endif //_PM_DATA_H_
