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
    Witch()=default;




    /*
    * D'tor of Witch class
    *
    * @result
    *      instance of Witch being destroyed.
    */
    ~Witch() override=default;



    /*
    * Get the card type
    *
    * @return
    *      the type of the card ("Witch").
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



    static const int WITCH_COINS = 2;
    static const int WITCH_FORCE = 11;
    static const int WITCH_DAMAGE = 10;
    static const int WITCH_FORCE_LOSS = 1;
};



/*
    * Create an instance of Witch
    *
    * @return
    *      unique_ptr pointing to the new Witch instance
    */
std::unique_ptr<Card> createWitch();

#endif //EX4_WITCH_H
