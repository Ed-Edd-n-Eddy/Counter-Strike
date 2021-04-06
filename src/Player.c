#include "Defines.h"
#include "Player.h"

#include <stdio.h>

int playerDealDamage(Player *damageReceiver, int pistType, int damage) {
    if (pistType == GLOCK) {
       return glockDealDamage(damageReceiver, damage);
    } else { //DEAG
        return deagDealDamage(damageReceiver, damage);
    }
}

int getDmgArmor(int armor, int armorDamage) {
    return armor < armorDamage ? armorDamage - armor : 0;
}

int glockDealDamage(Player *damageReceiver, int damage) {
        int armorDmg = damage / 2;
        int extraArmorDamage = getDmgArmor(damageReceiver->playerData.armor, armorDmg);
        if (damageReceiver->playerData.armor <= 0) {
            //deal 100% dmg
            damageReceiver->playerData.health -= damage;
        } else {
            //deal 50%
            damageReceiver->playerData.armor -= armorDmg; 
            damageReceiver->playerData.health -= (damage / 2) + extraArmorDamage;
        }
        if (damageReceiver->playerData.armor < 0) {
            damageReceiver->playerData.armor = 0;
        }
        printf("Enemy left with: %i health and %i armor\n", damageReceiver->playerData.health, damageReceiver->playerData.armor);
        return damageReceiver->playerData.health;
}

int deagDealDamage(Player *damageReceiver, int damage) {
        int armorDmg = damage / 4;
        int extraArmorDamage = getDmgArmor(damageReceiver->playerData.armor, armorDmg);
        if (damageReceiver->playerData.armor <= 0) {
            //deal 100% dmg
            damageReceiver->playerData.health -= damage;
        } else {
            //deal 75%
            damageReceiver->playerData.armor -= armorDmg; 
            damageReceiver->playerData.health -= damage - (damage / 4) + extraArmorDamage;
        }
        if (damageReceiver->playerData.armor < 0) {
            damageReceiver->playerData.armor = 0;
        }
        printf("Enemy left with: %i health and %i armor\n", damageReceiver->playerData.health, damageReceiver->playerData.armor);
        return damageReceiver->playerData.health;
}