//
// Created by Shirah Hassan on 1/12/23.
//

#include "Well.h"
Well::Well():
        Card("Well")
{}



void Well::applyEncounter(Player &player) const
{
    bool isNinja = (player.getJob() == "Ninja");
    if (!isNinja)
    {
        player.damage(WELL_FALL_DAMAGE);
    }
    printWellMessage(isNinja);
}



std::unique_ptr<Card> createWell()
{
    Well* wellPtr=new Well();
    std::unique_ptr<Card> well(wellPtr);
    return well;
}
