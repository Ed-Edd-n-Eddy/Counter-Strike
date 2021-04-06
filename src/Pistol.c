#include "Pistol.h"

#include <stdio.h>

int shoot(Pistol *pistol){

    if((pistol->currClipBullets == 0) && (pistol->remainingAmmo == 0)){
        printf("No ammo left.\n");
        return 0;
    }

    if (pistol->currClipBullets == 0) {
        printf("Reloading...\n");
        int clipSize = pistol->clipSize;

        if (pistol->remainingAmmo <= clipSize) {
            pistol->currClipBullets = pistol->remainingAmmo;
            pistol->remainingAmmo = 0;
        } else {
            pistol->currClipBullets = clipSize;
            pistol->remainingAmmo = pistol->remainingAmmo - clipSize;
        }
        printf("currClipBullets: %i, remainingAmmo: %i\n", pistol->currClipBullets, pistol->remainingAmmo);
        return 0;
    } else {
        pistol->currClipBullets--;
        return 1;
    }
}
