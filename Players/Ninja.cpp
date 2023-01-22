//
// Created by nrhbv on 06/01/2023.
//

#include "Ninja.h"



const std::string Ninja::m_job="Ninja";



Ninja::Ninja(const std::string &name):
        Player(name)
{}



std::unique_ptr<Player> createNinja(const std::string& name)
{
    Ninja* ninjaPtr=new Ninja(name);
    std::unique_ptr<Player> ninja=std::unique_ptr<Player>(ninjaPtr);
    return ninja;
}


void Ninja::addCoins(int coinsToAdd)
{
    if(coinsToAdd>ZERO_COINS)
    {
        m_coins+=2*coinsToAdd;
    }
}



const std::string& Ninja::getJob() const
{
    return m_job;
}