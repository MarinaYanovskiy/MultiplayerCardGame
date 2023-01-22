//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX4_CARD_H
#define EX4_CARD_H

#include <string>
#include "../Players/Player.h"
#include "../utilities.h"


class Card {
    /*------PAY ATTENTION - THIS CLASS IS ABSTRACT AND WE CAN'T CREATE A PURE INSTANCE OF IT--------------*/
public:

    /*
    * C'tor of Card class
    *
    * @return
    *      A new instance of Card.
    */
    Card(const std::string& name);



    /*
       * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card &) = default;
    Card &operator=(const Card &other) = default;



    /*
    * D'tor of Card class
    *
    * @result
    *      instance of Card being destroyed.
    */
    virtual ~Card()=0;



    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - the player who encountered the card.
    * @result
    *      modification of the player if needed.
    */
    virtual void applyEncounter(Player &player) const = 0;



    /*
    * Get the card type
    *
    * @return
    *      the type of the card.
    */
  //  virtual std::string getType() const=0;




    /*
    * Override << operator to support printing
    *
    * @return
    *      the Card details in OS format.
    */
    friend std::ostream &operator<<(std::ostream &stream, const Card &);

protected:
    /*
     * Prints additional card info if exists (for example- for special cards).
     *
     * @return
     *      void
    */
    virtual void printAdditionalInfo(std::ostream &stream) const;


    std::string m_name;

};


#endif //EX4_CARD_H
