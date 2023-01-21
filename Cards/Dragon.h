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
    Dragon()=default;



    /*
    * D'tor of Dragon class
    *
    * @result
    *      instance of Dragon being destroyed.
    */
    ~Dragon() override=default;



    /*
    * Get the card type
    *
    * @return
    *      the type of the card ("Dragon").
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



    static const int DRAGON_COINS = 1000;
    static const int DRAGON_FORCE = 25;
    static const int DRAGON_DAMAGE = -1;
};



/*
    * Create an instance of Dragon
    *
    * @return
    *      unique_ptr pointing to the new Dragon instance
    */
std::unique_ptr<Card> createDragon();

#endif //EX4_DRAGON_H
