//
// Created by Shirah Hassan on 1/12/23.
//

#include "Witch.h"
#define WITCH_COINS 2
#define WITCH_FORCE 11
#define WITCH_DAMAGE 10
#define WITCH_FORCE_LOSS 1

Witch::Witch():
        BattleCard("Witch",WITCH_DAMAGE,WITCH_FORCE,WITCH_COINS)

{}



void Witch::handlePlayerLoss(Player &player) const
{
    player.damage(m_damage);
    player.weaken(WITCH_FORCE_LOSS);
}


std::unique_ptr<Card> createWitch()
{
    Witch* witchPtr=new Witch();
    std::unique_ptr<Card> witch (witchPtr);
    return witch;
}
