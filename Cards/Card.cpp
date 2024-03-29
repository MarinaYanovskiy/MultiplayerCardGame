#include "Card.h"

Card::Card(const std::string& name):
m_name(name)
{
}



Card::~Card()
{}



std::ostream &operator<<(std::ostream &stream, const Card &card)
{
    printCardDetails(stream,card.m_name);
    card.printAdditionalInfo(stream);
    printEndOfCardDetails(stream);
    return stream;
}



void Card::printAdditionalInfo(std::ostream &stream) const
{}