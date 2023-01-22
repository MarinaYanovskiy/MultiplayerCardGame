//
// Created by nrhbv on 06/01/2023.
//

#ifndef EX4_MAIN_WARRIOR_H
#define EX4_MAIN_WARRIOR_H

#include <memory>
#include "Player.h"
#include "../utilities.h"

class Warrior : public Player{
public:
    /*
      * C'tor of Warrior class:
      *
      * @result
      *      An instance of Warrior
     */
    Warrior(const std::string& name);



    /*
    * D'tor of Warrior class
    *
    * @result
    *      instance of Warrior being destroyed.
    */
    ~Warrior() override=default;



    /*
     * Current Attack strength of Warrior - equals to (current level)+(2*current force).
     *
     * @return
     *      The current strength a Warrior can attack with
    */
    int getAttackStrength() const override;



    /*
    * Get the player job
    *
    * @return
    *      the job of the player ("Warrior").
    */
    const std::string& getJob() const override;




private:
    static const std::string m_job;
};



    /*
    * Create an instance of Warrior
    *
    * @return
    *      unique_ptr pointing to the new Warrior instance
    */
std::unique_ptr<Player> createWarrior(const std::string& name);


#endif //EX4_MAIN_WARRIOR_H
