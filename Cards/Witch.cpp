//
// Created by Shirah Hassan on 1/12/23.
//

#include "Witch.h"

void Witch::handlePlayerLoss(Player &player) const
{
    player.damage(WITCH_DAMAGE);
    player.weaken(WITCH_FORCE_LOSS);
}



std::string Witch::getType() const
{
    return "Witch";
}



int Witch::getForce() const
{
    return WITCH_FORCE;
}



int Witch::getCoins() const
{
    return WITCH_COINS;
}



int Witch::getDamage() const
{
    return WITCH_DAMAGE;
}



std::unique_ptr<Card> createWitch()
{
    Witch* witchPtr=new Witch();
    std::unique_ptr<Card> witch (witchPtr);
    return witch;
}
