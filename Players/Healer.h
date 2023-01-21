//
// Created by nrhbv on 06/01/2023.
//

#ifndef EX4_MAIN_HEALER_H
#define EX4_MAIN_HEALER_H
#include "Player.h"
#include <memory>
#include "../utilities.h"

class Healer : public Player{

public:
    /*
      * C'tor of Healer class:
      *
      * @result
      *      An instance of Healer
     */
    Healer(const std::string& name);



    /*
    * D'tor of Healer class
    *
    * @result
    *      instance of Healer being destroyed.
    */
    ~Healer() override=default;



    /*
     * Heal player with double amount of healPoints.
     *
     * @param healPoints - the healing points we want to add to a player
     *
     * @result
     *      increases player's health points
    */
    void heal(int healPoints);



    /*
    * Get the player job
    *
    * @return
    *      the job of the player ("Healer").
    */
    std::string getJob() const override;


private:
    static const std::string m_job;
};



/*
* Create an instance of Healer
*
* @return
*      unique_ptr pointing to the new Healer instance
*/
std::unique_ptr<Player> createHealer(const std::string& name);




#endif //EX4_MAIN_HEALER_H
