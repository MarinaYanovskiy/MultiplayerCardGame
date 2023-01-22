#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H
#include <iostream>
#include <string>
#include <cstring>
#include "HealthPoints.h"
#define DEFAULT_FORCE 5
#define DEFAULT_MAX_HP 100



class Player
    /*------PAY ATTENTION - THIS CLASS IS ABSTRACT AND WE CAN'T CREATE A PURE INSTANCE OF IT--------------*/
{
    
//----------------------class methods----------------------
    public:
    
   /*
     * C'tor of the player:
     *
     * @param m_name - The name of the player.
     * @result
     *      An instance of Player
    */
    Player(const std::string& name);



    /*
     * Copy C'tor of the player:
     *
     * @param playerToCopy - The player we want to duplicate.
     * @result
     *      An instance of Player
    */
    Player(const Player& playerToCopy);



    /*
     * Copy player to an existing one
     *
     * @param playerToCopy - The player we want to copy the data from.
     * @return
     *      The reference to 'this' player
    */
    Player& operator=(const Player& playerToCopy) =default;



    /*
     * D'tor of Player
     *
     * @result
     *      The instance of Player being destroyed
    */
    virtual ~Player() =0;
    
    
    
    
//---------------------Getters----------------------
    /*
     * Current Attack strength- equals to (current level)+(current force)
     *
     * @return
     *      The current strength a player can attack with
    */
    virtual int getAttackStrength() const;



    /*
     * Get the player's name
     *
     * @return
     *      name of the player.
    */
    std::string getName() const;



    /*
     * Get the player's coins
     *
     * @return
     *      amount of coins a player currently has.
    */
    int getCoins() const;



    /*
     * Get the player's job
     *
     * @return
     *      the job (type) of a player.
    */

    virtual const std::string& getJob() const = 0;



//------------------update player--------------------

    /*
     * Level up a player
     *
     * @result
     *      increases player's level
    */
    void levelUp();



    /*
     * Buff player's force
     * @param extraForce- the force we want to add to a player
     *
     * @result
     *      increases player's force
    */
    void buff(int extraForce);



    /*
     * Damage player's force
     * @param lessForce- the force we want to damage a player with
     *
     * @result
     *      decrease player's force
    */
    void weaken(int lessForce);



    /*
     * Heal player
     * @param healPoints - the healing points we want to add to a player
     *
     * @result
     *      increases player's health points
    */
    virtual void heal(int healPoints);



    /*
     * Damage player health
     * @param damagePoints- the amount of damage to be caused.
     *
     * @result
     *      decreases player's health points.
    */
    void damage(int damagePoints);



    /*
     * Add coins to a player
     * @param coinsToAdd- the amount of money we want to give to a player.
     *
     * @result
     *      increases player's coin's amount.
    */
    virtual void addCoins(int coinsToAdd);



    /*
     * Make a player pay
     * @param payment - the amount of money the player needs to pay.
     *
     * @return
     *      True if the payment has done successfully
     *      False if the player doesn't have enough money
    */
    bool pay(int payment);



    /*
     * Kill a player
     *
     * @result
     *      Decrease player's healthPoints to 0.
    */
    void die();
    
//---------------informative functions---------------------

    
    /*
     * Print player's information.
     *
     * @return
     *      player's data in print format.
    */
    friend  std::ostream& operator <<(std::ostream& os, const Player& player);



    /*
     * Check if the player won.
     *
     * @return
     *      True- if the player reached to level 10.
     *      False otherwise.
    */
    bool isWin() const;



    /*
     * Check if the player lost.
     *
     * @return
     *      True- if the player's healthPoints reached to 0.
     *      False otherwise.
    */
    bool isLose() const;




//----------------------class fields----------------------
protected:
    std::string m_name;
    int m_level;
    int m_force;
    HealthPoints m_healthPoints;
    int m_coins;


    static const int NO_POINTS=0;
    static const int MAX_LEVEL=10;
    static const int LEVEL_ONE=1;
    static const int ZERO_COINS=0;
    static const int STARTING_AMOUNT_OF_COINS=10;
    static const int MINIMUM_ALLOWED_VALUE=0;
};


#endif