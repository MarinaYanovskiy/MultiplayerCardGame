//
// Created by Shirah Hassan on 1/12/23.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H
#include <memory>
#include "BattleCard.h"

class Dragon : public BattleCard {
public:
    /*
    * C'tor of Dragon class
    *
    * @return
    *      A new instance of Dragon.
    */
    Dragon();



    /*
    * D'tor of Dragon class
    *
    * @result
    *      instance of Dragon being destroyed.
    */
    ~Dragon() override=default;



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
    * Create an instance of Dragon
    *
    * @return
    *      unique_ptr pointing to the new Dragon instance
    */
std::unique_ptr<Card> createDragon();

#endif //EX4_DRAGON_H
