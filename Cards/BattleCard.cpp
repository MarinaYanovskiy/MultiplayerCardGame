//
// Created by Shirah Hassan on 1/11/23.
//

#include "BattleCard.h"

BattleCard::~BattleCard() {}



void BattleCard::applyEncounter(Player &player) const
{
    if (player.getAttackStrength() >= getForce())
    {
        player.levelUp();
        player.addCoins(getCoins());
        printWinBattle(player.getName(), getType());
    }
    else
    {
        handlePlayerLoss(player);
        printLossBattle(player.getName(), getType());
    }
}



void BattleCard::printAdditionalInfo(std::ostream &stream) const
{
    printMonsterDetails(stream, getForce(), getDamage(), getCoins(), (getType()=="Dragon"));
}