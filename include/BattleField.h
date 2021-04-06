#ifndef BATTLEFIELD_H_
#define BATTLEFIELD_H_

#include "Player.h"

typedef struct {
  Player players[PLAYERS_COUNT];
} BattleField;

/*
Skeleton function
*/
void createPlayers();

/*
Skeleton function
*/
void buyPistols();

/*
Skeleton function
*/
void startBattle();

/*
Function that implements shooting. Returns true if shooter player
kills target player.
*/
int playerShoots(Player * shooter, Player * target);

#endif /* BATTLEFIELD_H_ */