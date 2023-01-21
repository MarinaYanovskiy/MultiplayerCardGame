//
// Created by Shirah Hassan on 1/11/23.
//

#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H
#include <memory>
#include "Card.h"

class Treasure : public Card {
public:
    /*
    * C'tor of Treasure class
    *
    * @return
    *      A new instance of Treasure.
    */
    Treasure()=default;



    /*
    * D'tor of Treasure class
    *
    * @result
    *      instance of Treasure being destroyed.
    */
    ~Treasure() override=default;



    /*
    * Play with Treasure card
    *
    * @param player - the player who encountered the card.
    * @result
    *      modification of the player if needed.
    */
    void applyEncounter(Player &player) const override;



    /*
    * Get the card type
    *
    * @return
    *      the type of the card ("Treasure").
    */
    std::string getType() const override;

private:
    static const int TREASURE = 10;
};



/*
    * Create an instance of Treasure
    *
    * @return
    *      unique_ptr pointing to the new Treasure instance
    */
std::unique_ptr<Card> createTreasure();

#endif //EX4_TREASURE_H
