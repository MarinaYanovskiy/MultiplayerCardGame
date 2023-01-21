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
    Gremlin()=default;



    /*
    * D'tor of Gremlin class
    *
    * @result
    *      instance of Gremlin being destroyed.
    */
    ~Gremlin() override=default;



    /*
    * Get the card type
    *
    * @return
    *      the type of the card ("Gremlin").
    */
    std::string getType() const override;



private:
    /*
     * Hande the player if he lost in the battle.
     *
     * @result
     *      modifications to the player based on the card type.
     */
    void handlePlayerLoss(Player &player) const override;



    /*
    * Get the card attack force
    *
    * @return
    *      attack force.
    */
    virtual int getForce() const override;



    /*
    * Get the card coins prize
    *
    * @return
    *      the coins prize for winning.
    */
    virtual int getCoins() const override;



    /*
    * Get the card damage force
    *
    * @return
    *      the damage force.
    */
    virtual int getDamage() const override;



    static const int GREMLIN_COINS = 2;
    static const int GREMLIN_FORCE = 5;
    static const int GREMLIN_DAMAGE = 10;
};



/*
    * Create an instance of Gremlin
    *
    * @return
    *      unique_ptr pointing to the new Gremlin instance
    */
std::unique_ptr<Card> createGremlin();

#endif //EX4_GREMLIN_H
