#include "BattleField.h"
#include "Player.h"
#include "Pistol.h"
#include "Defines.h"

#include <stdio.h>
#include <stdlib.h>

Player players[PLAYERS_COUNT];

void createPlayers() {

  int playerHealth = 0;
  int playerArmor = 0;

  for (int i = 0; i < PLAYERS_COUNT; ++i) {
    scanf("%d %d", &playerHealth, &playerArmor);
    PlayerVitalData playerData;
    playerData.health = playerHealth;
    playerData.armor = playerArmor;
    players[i].playerData = playerData;
  }
}

void buyPistols() {

  int pistolId = 0;
  int pistolDamagePerRound = 0;
  int pistolClipSize = 0;
  int pistolRemainingAmmo = 0;

  for (int i = 0; i < PLAYERS_COUNT; ++i) {
    scanf("%d %d %d %d", &pistolId, &pistolDamagePerRound, &pistolClipSize, &pistolRemainingAmmo);
    Pistol pistol;
    pistol.pistolType = pistolId;
    pistol.damagePerRound = pistolDamagePerRound;
    pistol.clipSize = pistolClipSize;
    pistol.remainingAmmo = pistolRemainingAmmo;
    pistol.currClipBullets = pistolClipSize;

    players[i].pistol = pistol;
  }
}

void startBattle() {
  int loopFlag = 1;
  while(loopFlag){

    for (int i = 0; i < PLAYERS_COUNT; i++) {
      printf("PlayerID %d turn:\n", i);
      if (i == 0) {
        //player 1
        if (playerShoots(&players[PLAYER_ONE], &players[PLAYER_TWO])) {
          printf("\nPlayer with ID: %d wins!\n", i);
          loopFlag = 0;
          break;
        }
      } else {
        if (playerShoots(&players[PLAYER_TWO], &players[PLAYER_ONE])) {
          printf("\nPlayer with ID: %d wins!\n", i);
          loopFlag = 0;
          break;
        }
      }
      printf("\n");
    }
  }
}

int playerShoots(Player *shooter, Player *target) {
  int shots = shooter->pistol.pistolType == GLOCK ? ROUNDS_PER_FIRE : 1; // glock shoots 3, DEAG 1
  for (int i = 0; i < shots; i++) {
    if (shoot(&shooter->pistol)) {
    //pistol dealt damage
    int targetHealth = playerDealDamage(target, shooter->pistol.pistolType, shooter->pistol.damagePerRound);
      if (targetHealth <= 0) {
        //target killed
        return 1;
      }
    } else {
      break;
    }
  }
  return 0;
}