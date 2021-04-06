#ifndef DEFINES_H_
#define DEFINES_H_

enum PistolType {
  GLOCK, DESERT_EAGLE
};

enum GlockDefines {
  ROUNDS_PER_FIRE = 3
};

enum PlayerDefines {
  PLAYER_ONE, PLAYER_TWO, PLAYERS_COUNT
};

typedef struct {
  int health;
  int armor;
} PlayerVitalData;

#endif /* DEFINES_H_ */