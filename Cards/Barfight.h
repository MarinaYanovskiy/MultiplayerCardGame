//
// Created by Shirah Hassan on 1/12/23.
//

#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H
#include <memory>
#include "Card.h"

class Barfight : public Card {
public:
    /*
    * C'tor of Barfight class
    *
    * @return
    *      A new instance of Barfight.
    */
    Barfight();



    /*
    * D'tor of Barfight class
    *
    * @result
    *      instance of Barfight being destroyed.
    */
    ~Barfight() override=default;



    /*
    * Play with Barfight card
    *
    * @param player - the player who encountered the card.
    * @result
    *      modification of the player if needed.
    */
    void applyEncounter(Player &player) const override;




private:
    static const int BAR_FIGHT_DAMAGE = 10;
};



/*
    * Create an instance of Barfight
    *
    * @return
    *      unique_ptr pointing to the new Barfight instance
    */
std::unique_ptr<Card> createBarFight();

#endif //EX4_BARFIGHT_H
