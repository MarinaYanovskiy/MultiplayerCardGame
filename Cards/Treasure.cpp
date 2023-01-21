//
// Created by Shirah Hassan on 1/11/23.
//

#include "Treasure.h"

std::string Treasure::getType() const
{
    return "Treasure";
}



void Treasure::applyEncounter(Player &player) const
{
    player.addCoins(TREASURE);
    printTreasureMessage();
}



std::unique_ptr<Card> createTreasure()
{
    Treasure* treasurePtr=new Treasure();
    std::unique_ptr<Card> treasure(treasurePtr);
    return treasure;
}