//
// Created by Shirah Hassan on 1/12/23.
//

#include "Dragon.h"
#define DRAGON_COINS  1000
#define DRAGON_FORCE 25

Dragon::Dragon():
        BattleCard("Dragon", DEFAULT_MAX_HP,DRAGON_FORCE,DRAGON_COINS)
{}


std::unique_ptr<Card> createDragon()
{
    Dragon* dragonPtr=new Dragon();
    std::unique_ptr<Card> dragon (dragonPtr);
    return dragon;
}



void Dragon::handlePlayerLoss(Player &player) const {
    player.die();
}
