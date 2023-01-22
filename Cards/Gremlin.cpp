//
// Created by Shirah Hassan on 1/12/23.
//

#include "Gremlin.h"

#define GREMLIN_COINS 2
#define GREMLIN_FORCE 5
#define GREMLIN_DAMAGE 10

Gremlin::Gremlin():
        BattleCard("Gremlin",GREMLIN_DAMAGE,GREMLIN_FORCE,GREMLIN_COINS)
{}



void Gremlin::handlePlayerLoss(Player &player) const
{
    player.damage(m_damage);
}



std::unique_ptr<Card> createGremlin()
{
    Gremlin* gremlinPtr=new Gremlin();
    std::unique_ptr<Card> gremlin (gremlinPtr);
    return gremlin;
}
