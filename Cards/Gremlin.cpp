//
// Created by Shirah Hassan on 1/12/23.
//

#include "Gremlin.h"

std::string Gremlin::getType() const
{
    return "Gremlin";
}



int Gremlin::getForce() const
{
    return GREMLIN_FORCE;
}



int Gremlin::getCoins() const
{
    return GREMLIN_COINS;
}



int Gremlin::getDamage() const
{
    return GREMLIN_DAMAGE;
}



void Gremlin::handlePlayerLoss(Player &player) const
{
    player.damage(GREMLIN_DAMAGE);
}



std::unique_ptr<Card> createGremlin()
{
    Gremlin* gremlinPtr=new Gremlin();
    std::unique_ptr<Card> gremlin (gremlinPtr);
    return gremlin;
}
