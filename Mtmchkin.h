#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include <iostream>
#include "Players/Player.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
#include "Players/Warrior.h"
#include "Exception.h"
#include "Cards/Card.h"
#include "Cards/Witch.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Mana.h"
#include "Cards/Gremlin.h"
#include "Cards/Merchant.h"
#include "Cards/Well.h"
#include "Cards/Treasure.h"
#include <vector>
#include <map>
#include <memory>
#include <list>



class Mtmchkin{

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);

    /*
    * Disable the copy C'tor and the '=' operator.
    *
    * @result
     *     we will have only one instance for every game.
    */
    Mtmchkin(const Mtmchkin&)=delete;
    Mtmchkin& operator=(const Mtmchkin&)=delete;

    /*
    * D'tor of Mtmchkin class
    *
    * @result
    *      A Mtmchkin instance being destroyed.
    */
    ~Mtmchkin()=default;


    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    /*
    *  Create the players that will play.
    *
    *  @result setting the m_activePlayers field.
    *
    */
    void createPlayers();



    /*
    *  Create the deck of cards for the game.
    *
    *  @result setting the m_deckOfCards field.
    *
    */
    void createDeck(const std::string &fileName);



    /*
    *  Create an empty group of players.
    *
    *  @result setting the m_numOfPlayers field.
    *
    */
    void createEmptyGroup();



    /*
    *  Check if a valid data for the group size was entered.
    *
    *  @return
    *         True- if the data is legal.
     *         False otherwise.
    */
    static bool isValidNumber(const std::string& number);



    /*
    *  Check if a valid data for the player was inserted.
    *
    *  @return
    *         True- if the data is legal.
     *         False otherwise.
    */
    static bool isValidPlayer(const std::string& name,const std::string& job);



 //----------------------------Class Fields---------------------------------//
    int m_roundsPlayed;
    int m_chosenCardIndex;
    int m_numOfCards;
    int m_numOfPlayers;
    std::list<std::unique_ptr<Player>> m_activePlayers;
    std::list<std::unique_ptr<Player>> m_winnerPlayers;
    std::list<std::unique_ptr<Player>> m_loserPlayers;
    std::vector<std::unique_ptr<Card>> m_deckOfCards;

    //------we will use the next variables for creating objects by their name (in string format)----------//
    static std::map<std::string,std::unique_ptr<Player> (*)(const std::string&)> TYPE_OF_PLAYER;
    static std::map<std::string,std::unique_ptr<Card> (*)()> TYPE_OF_CARD;
};

#endif /* MTMCHKIN_H_ */
