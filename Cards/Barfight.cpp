//
// Created by Shirah Hassan on 1/12/23.
//

#include "Barfight.h"

void Barfight::applyEncounter(Player &player) const
{
    bool isWarrior = (player.getJob() == "Warrior");
    if (!isWarrior)
    {
        player.damage(BAR_FIGHT_DAMAGE);
    }
    printBarfightMessage(isWarrior);
}



std::string Barfight::getType() const
{
    return "Barfight";
}



std::unique_ptr<Card> createBarFight()
{
    Barfight* barfightPtr=new Barfight();
    std::unique_ptr<Card> barFight(barfightPtr);
    return barFight;
}
