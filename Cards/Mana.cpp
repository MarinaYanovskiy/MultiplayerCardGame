//
// Created by Shirah Hassan on 1/12/23.
//

#include "Mana.h"
Mana::Mana():
        Card("Mana")
{}




void Mana::applyEncounter(Player &player) const
{
    bool isHealer = (player.getJob() == "Healer");
    if (isHealer)
    {
        player.heal(MANA_HP_INCREASE);
    }
    printManaMessage(isHealer);
}



std::unique_ptr<Card> createMana()
{
    Mana* manaPtr=new Mana();
    std::unique_ptr<Card> mana (manaPtr);
    return mana;
}

