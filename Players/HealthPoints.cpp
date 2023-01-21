#include "HealthPoints.h"


HealthPoints::HealthPoints(int maxHP)
{
    if(maxHP<0)
    {
        throw HealthPoints::InvalidArgument();
    }
    m_currentPoints=maxHP;
    m_maxPoints=maxHP;
}



HealthPoints::HealthPoints(const HealthPoints& objectToCopy):
    m_currentPoints(objectToCopy.m_currentPoints),
    m_maxPoints(objectToCopy.m_maxPoints)
{
}



HealthPoints &HealthPoints::operator+=(int addPoints) {
    m_currentPoints += addPoints;
    if (m_currentPoints > m_maxPoints)
    {
        m_currentPoints = m_maxPoints;
    }
    if (m_currentPoints < NO_POINTS)
    {
        m_currentPoints = NO_POINTS;
    }

    return *this;
}



HealthPoints &HealthPoints::operator-=(int removePoints)
        {
    *this += -(removePoints);
    return *this;

}



bool operator ==(const HealthPoints& first, const HealthPoints& second)
{
    if(first.getCurrentPoints()==second.getCurrentPoints())
    {
        return true;
    }
    return false;
}



bool operator !=(const HealthPoints& first, const HealthPoints& second)
{
    return !(first==second);
}



bool operator >(const HealthPoints& first, const HealthPoints& second)
{
    if(first.getCurrentPoints()>second.getCurrentPoints())
    {
        return true;
    }
    return false;
}



bool operator <(const HealthPoints& first, const HealthPoints& second)
{
    return (first!=second) && (!(first>second));
}



bool operator <=(const HealthPoints& first, const HealthPoints& second)
{
    return !(first>second);
}



bool operator >=(const HealthPoints& first, const HealthPoints& second)
{
    return !(first<second);
}


int HealthPoints::getCurrentPoints() const
{
    return  m_currentPoints;
}



HealthPoints operator+(int addPoints, const HealthPoints& healthPoints)
{
    HealthPoints result(healthPoints);
    result += addPoints;
    return result;
}



HealthPoints operator+(const HealthPoints& healthPoints, int addPoints)
{
    HealthPoints result(healthPoints);
    result += addPoints;
    return result;
}



HealthPoints operator-(int removePoints, const HealthPoints& healthPoints) {
    HealthPoints result(healthPoints);
    result -= removePoints;
    return result;
}



HealthPoints operator-(const HealthPoints& healthPoints, int removePoints) {
    HealthPoints result(healthPoints);
    result -= removePoints;
    return result;
}
