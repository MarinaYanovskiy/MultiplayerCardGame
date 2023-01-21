#include "Card.h"

Card::~Card()
{}



std::ostream &operator<<(std::ostream &stream, const Card &card)
{
    printCardDetails(stream, card.getType());
    card.printAdditionalInfo(stream);
    printEndOfCardDetails(stream);
    return stream;
}



void Card::printAdditionalInfo(std::ostream &stream) const
{}