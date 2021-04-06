#ifndef PLAYER_H_
#define PLAYER_H_

#include "Pistol.h"
#include "Defines.h"

typedef struct {
  PlayerVitalData playerData;
  Pistol pistol;
  int playerId;
} Player;

/*
Function that takes a pointer to a player and applies the damage specified
to their vital stats. Returns the remaining HP of that player. 
*/
int playerDealDamage(Player * damageReceiver, int pistType, int damage);

/*
Helper function in Player.c that calculates armor damage when damage dealt to
armor is greater than remaining armor.
*/
int getDmgArmor(int armor, int armorDamage);

/*
Helper function in Player.c that calculates and applies damage dealt with a 
glock pistol.
*/
int glockDealDamage(Player * damageReceiver, int damage);

/*
Helper function in Player.c that calculates and applies damage dealt with a 
DEAG pistol.
*/
int deagDealDamage(Player * damageReceiver, int damage);

#endif /* PLAYER_H_ */