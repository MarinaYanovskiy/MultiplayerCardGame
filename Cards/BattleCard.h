//
// Created by Shirah Hassan on 1/11/23.
//

#ifndef EX4_BATTLECARD_H
#define EX4_BATTLECARD_H

#include "Card.h"

class BattleCard : public Card {
    /*------PAY ATTENTION - THIS CLASS IS ABSTRACT AND WE CAN'T CREATE A PURE INSTANCE OF IT--------------*/
public:

    /*
    * C'tor of BattleCard class
    *
    * @return
    *      A new instance of BattleCard.
    */
    BattleCard(const std::string& name, int damage, int force, int coins);



    /*
    * D'tor of BattleCard class
    *
    * @result
    *      instance of BattleCard being destroyed.
    */
    virtual ~BattleCard() = 0;




    /*
    * Play with BattleCard
    *
    * @param player - the player who encountered the card.
    * @result
    *      modification of the player if needed.
    */
    void applyEncounter(Player &player) const override;





protected:

    /*
    * Hande the player if he lost in the battle.
    *
    * @result
    *      modifications to the player based on the card type.
    */
    virtual void handlePlayerLoss(Player &player) const=0;



private:
    /*
     * Prints additional card info if exists (for example- for special cards).
     *
     * @return
     *      void
    */
   void printAdditionalInfo(std::ostream &stream) const override;


protected:
    int m_damage;
    int m_force;
    int m_coins;
};


#endif //EX4_BATTLECARD_H
