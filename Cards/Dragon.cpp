//
// Created by Shirah Hassan on 1/12/23.
//

#include "Dragon.h"

std::string Dragon::getType() const
{
    return "Dragon";
}



int Dragon::getForce() const
{
    return DRAGON_FORCE;
}



int Dragon::getCoins() const
{
    return DRAGON_COINS;
}



int Dragon::getDamage() const
{
    return DRAGON_DAMAGE;
}



std::unique_ptr<Card> createDragon()
{
    Dragon* dragonPtr=new Dragon();
    std::unique_ptr<Card> dragon (dragonPtr);
    return dragon;
}



void Dragon::handlePlayerLoss(Player &player) const {
    player.die();
}
