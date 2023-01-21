//
// Created by Shirah Hassan on 1/12/23.
//

#ifndef EX4_WELL_H
#define EX4_WELL_H
#include <memory>
#include "Card.h"

class Well : public Card {
public:
    /*
    * C'tor of Well class
    *
    * @return
    *      A new instance of Well.
    */
    Well()=default;



    /*
    * D'tor of Well class
    *
    * @result
    *      instance of Well being destroyed.
    */
    ~Well() override=default;



    /*
    * Play with Well card
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
    *      the type of the card ("Well").
    */
    std::string getType() const override;



private:
    static const int WELL_FALL_DAMAGE = 10;
};


/*
    * Create an instance of Well
    *
    * @return
    *      unique_ptr pointing to the new Well instance
    */
std::unique_ptr<Card> createWell();

#endif //EX4_WELL_H
