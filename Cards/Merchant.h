//
// Created by Shirah Hassan on 1/12/23.
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H
#include <memory>
#include "Card.h"

class Merchant : public Card {
public:
    /*
    * C'tor of Merchant class
    *
    * @return
    *      A new instance of Merchant
    */
    Merchant();



    /*
    * D'tor of Merchant class
    *
    * @result
    *      instance of Merchant being destroyed.
    */
    ~Merchant() override=default;



    /*
    * Play with Merchant card
    *
    * @param player - the player who encountered the card.
    * @result
    *      modification of the player if needed.
    */
    void applyEncounter(Player &player) const override;




private:



    /*
    * Check input for the card
    *
    * @param str - the input to check.
    * @result
    *       true - if legal input was entered.
    *      else otherwise.
    */
    static bool isValidInput(const std::string& input);



    static const int FORCE_PRICE = 10;
    static const int HEALTH_PRICE = 5;
    static const int BOOST = 1;
    static const int LEAVE_CMD = 0;
    static const int HEALTH_POTION_CMD = 1;
    static const int FORCE_BOOST_CMD = 2;
};


/*
    * Create an instance of Merchant
    *
    * @return
    *      unique_ptr pointing to the new Merchant instance
    */
std::unique_ptr<Card> createMerchant();


#endif //EX4_MERCHANT_H
