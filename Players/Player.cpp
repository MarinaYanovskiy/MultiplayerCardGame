#include "Player.h"
#include "../utilities.h"
using namespace std;



//*********************class methods*********************



//--------------------c'tor, copy-c'tor------------------
Player::Player(const string name) :
    m_name(name),
    m_level(LEVEL_ONE),
    m_force(DEFAULT_FORCE),
    m_healthPoints(DEFAULT_MAX_HP),
    m_coins(STARTING_AMOUNT_OF_COINS)
{
}



//copy-c'tor
Player::Player(const Player& playerToCopy) :
    m_name(playerToCopy.m_name), 
    m_level(playerToCopy.m_level),
    m_force(playerToCopy.m_force),
    m_healthPoints(playerToCopy.m_healthPoints),
    m_coins(playerToCopy.m_coins)
{
}



Player::~Player() {}



//---------------------Getters------------------------------
int Player::getAttackStrength() const
{
    return m_force+m_level;
}



std::string Player::getName() const
{
    return m_name;
}



int Player::getCoins() const
{
    return  m_coins;
}



//------------------update player-----------------------
void Player::levelUp()
{
    if(m_level<MAX_LEVEL)
    {
        m_level++;
    }
}



void Player::buff(const int extraForce)
{
    if(extraForce>MINIMUM_ALLOWED_VALUE)
    {
        m_force+=extraForce;
    }
}



void Player::weaken(int lessForce)
{
    if(lessForce>MINIMUM_ALLOWED_VALUE && m_force>MINIMUM_ALLOWED_VALUE)
    {
        m_force-=lessForce;
    }
    if(m_force<MINIMUM_ALLOWED_VALUE)
    {
        m_force=MINIMUM_ALLOWED_VALUE;
    }
}



void Player::heal(int healPoints)
{
    if(healPoints>MINIMUM_ALLOWED_VALUE)
    {
       m_healthPoints+=healPoints;
    }
}



void Player::die()
{
    int currentPoints=m_healthPoints.getCurrentPoints();
    m_healthPoints-=currentPoints;
}



void Player::damage(int damagePoints)
{
    if(damagePoints>MINIMUM_ALLOWED_VALUE)
    {
       m_healthPoints-=damagePoints;
    }
}



void Player::addCoins(int coinsToAdd)
{
    if(coinsToAdd>MINIMUM_ALLOWED_VALUE)
    {
        m_coins+=coinsToAdd;
    }
}



bool Player::pay(int payment)
{
    if(payment>MINIMUM_ALLOWED_VALUE)
    {
        if(m_coins-payment<MINIMUM_ALLOWED_VALUE)
        {
            return false;
        }
        else
        {
            m_coins-=payment;
            return true;
        }
    }
    return true;
}
//---------------informative functions---------------------


std::ostream& operator<<(std::ostream& os, const Player& player)
{
    printPlayerDetails(os,player.m_name, player.getJob(), player.m_level, player.m_force, player.m_healthPoints.getCurrentPoints(), player.m_coins);
  return os;
}



bool Player::isWin() const
{
    return m_level==MAX_LEVEL;
}



bool Player::isLose() const
{
    return m_healthPoints==NO_POINTS;
}
