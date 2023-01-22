//
// Created by Shirah Hassan on 1/12/23.
//

#ifndef EX4_GREMLIN_H
#define EX4_GREMLIN_H
#include <memory>
#include "BattleCard.h"

class Gremlin : public BattleCard {
public:
    /*
    * C'tor of Gremlin class
    *
    * @return
    *      A new instance of Gremlin.
    */
    Gremlin();



    /*
    * D'tor of Gremlin class
    *
    * @result
    *      instance of Gremlin being destroyed.
    */
    ~Gremlin() override=default;




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
    * Create an instance of Gremlin
    *
    * @return
    *      unique_ptr pointing to the new Gremlin instance
    */
std::unique_ptr<Card> createGremlin();

#endif //EX4_GREMLIN_H
