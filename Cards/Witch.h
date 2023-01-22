//
// Created by Shirah Hassan on 1/12/23.
//

#ifndef EX4_WITCH_H
#define EX4_WITCH_H
#include <memory>
#include "BattleCard.h"

class Witch : public BattleCard {
public:
    /*
    * C'tor of Witch class
    *
    * @return
    *      A new instance of Witch.
    */
    Witch();




    /*
    * D'tor of Witch class
    *
    * @result
    *      instance of Witch being destroyed.
    */
    ~Witch() override=default;



private:
    /*
     * Hande the player if he lost in the battle.
     *
     * @result
     *      modifications to the player based on the card type.
     */
    void handlePlayerLoss(Player &player) const override;
};



/*
    * Create an instance of Witch
    *
    * @return
    *      unique_ptr pointing to the new Witch instance
    */
std::unique_ptr<Card> createWitch();

#endif //EX4_WITCH_H
