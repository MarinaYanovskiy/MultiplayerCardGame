//
// Created by nrhbv on 06/01/2023.
//

#ifndef EX4_MAIN_NINJA_H
#define EX4_MAIN_NINJA_H

#include <memory>
#include "Player.h"
#include "../utilities.h"

class Ninja : public Player{

public:

    /*
      * C'tor of Ninja class:
      *
      * @result
      *      An instance of Ninja
     */
    Ninja(const std::string& name);



    /*
    * D'tor of Ninja class
    *
    * @result
    *      instance of Ninja being destroyed.
    */
    ~Ninja() override=default;



    /*
     * Add double amount of coins to a player
     * @param coinsToAdd- the amount of money we want to give to a player.
     *
     * @result
     *      increases player's coin's amount.
    */
    void addCoins (int coinsToAdd) override;



    /*
    * Get the player job
    *
    * @return
    *      the job of the player ("Ninja").
    */
    const std::string& getJob() const override;


private:
    static const std::string m_job;
};



/*
* Create an instance of Ninja
*
* @return
*      unique_ptr pointing to the new Ninja instance
*/
std::unique_ptr<Player> createNinja(const std::string& name);




#endif //EX4_MAIN_NINJA_H
