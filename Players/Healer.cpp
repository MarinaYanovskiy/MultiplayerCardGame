//
// Created by nrhbv on 06/01/2023.
//

#include "Healer.h"

const std::string Healer::m_job="Healer";



Healer::Healer(const std::string &name):
        Player(name)
{
}



std::unique_ptr<Player> createHealer(const std::string& name)
{
    Healer* healerPtr=new Healer(name);
    std::unique_ptr<Player> healer=std::unique_ptr<Player>(healerPtr);
    return healer;
}



void Healer::heal(int healPoints)
{
    if(healPoints>NO_POINTS)
    {
        m_healthPoints+= (2*healPoints);
    }
}



const std::string& Healer::getJob() const
{
    return m_job;
}