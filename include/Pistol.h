#ifndef PISTOL_H_
#define PISTOL_H_

#include "Defines.h"


typedef struct {
  enum PistolType pistolType;
  int damagePerRound;
  int clipSize;
  int currClipBullets;
  int remainingAmmo;
} Pistol;

/*
Shoots a single bullet from a pistol. Returns 0 or 1 indicating wheter the pistol
dealt any damage. Handles pistol reloads and out of ammo edge cases.
*/
int shoot(Pistol * pistol);

#endif /* PISTOL_H_ */