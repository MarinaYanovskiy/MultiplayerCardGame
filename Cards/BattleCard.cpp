//
// Created by Shirah Hassan on 1/11/23.
//

#include "BattleCard.h"
BattleCard::BattleCard(const std::string& name, int damage, int force, int coins) :
        Card(name),
        m_damage(damage),
        m_force(force),
        m_coins(coins)
{}



BattleCard::~BattleCard() {}



void BattleCard::applyEncounter(Player &player) const
{
    if (player.getAttackStrength() >= m_force)
    {
        player.levelUp();
        player.addCoins(m_coins);
        printWinBattle(player.getName(), m_name);
    }
    else
    {
        handlePlayerLoss(player);
        printLossBattle(player.getName(), m_name);
    }
}



void BattleCard::printAdditionalInfo(std::ostream &stream) const
{
    printMonsterDetails(stream, m_force,m_damage, m_coins, (m_name=="Dragon"));
}