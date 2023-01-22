//
// Created by Shirah Hassan on 1/12/23.
//

#ifndef EX4_MANA_H
#define EX4_MANA_H
#include <memory>
#include "Card.h"

class Mana : public Card{
public:
    /*
    * C'tor of Mana class
    *
    * @return
    *      A new instance of Mana.
    */
    Mana();



    /*
    * D'tor of Mana class
    *
    * @result
    *      instance of Mana being destroyed.
    */
    ~Mana() override=default;



    /*
    * Play with Mana card
    *
    * @param player - the player who encountered the card.
    * @result
    *      modification of the player if needed.
    */
    void applyEncounter(Player &player) const override;




private:
    static const int MANA_HP_INCREASE = 10;
};



/*
    * Create an instance of Mana
    *
    * @return
    *      unique_ptr pointing to the new Mana instance
    */
std::unique_ptr<Card> createMana();

#endif //EX4_MANA_H
