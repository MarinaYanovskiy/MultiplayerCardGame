//
// Created by nrhbv on 06/01/2023.
//

#include "Warrior.h"



const std::string Warrior::m_job="Warrior";



Warrior::Warrior(const std::string& name):
    Player(name)
{
}



std::unique_ptr<Player> createWarrior(const std::string& name)
{
    Warrior* warriorPtr= new Warrior(name);
    std::unique_ptr<Player> warrior=std::unique_ptr<Player>(warriorPtr);
    return warrior;
}



int Warrior::getAttackStrength() const
{
    return (m_force*2 + m_level);
}



const std::string& Warrior::getJob() const
{
    return m_job;
}