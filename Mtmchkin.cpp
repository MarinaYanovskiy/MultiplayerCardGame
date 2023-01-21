#include "Mtmchkin.h"
#include "utilities.h"
#include <fstream>
#include <algorithm>
#include <set>

#define BACK_SPACE ""
#define MINIMUM_NUM_OF_PLAYERS 2
#define MAXIMUM_NUM_OF_PLAYERS 6
#define MINIMUM_NUM_OF_CARDS 5
#define MAX_NAME_LENGTH 15
#define LETTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
const std::set<std::string> PLAYER_TYPES {"Ninja","Warrior","Healer"};
const std::set<std::string> CARD_TYPES {"Gremlin","Witch","Dragon","Mana","Barfight","Treasure","Merchant","Well"};

using std::ifstream;
using std::ofstream;
using std::vector;
using std::string;
using std::unique_ptr;
using std::unique_ptr;
using std::map;
using std::list;


map<string,unique_ptr<Player> (*)(const string&)> Mtmchkin::TYPE_OF_PLAYER{
    {"Ninja", &createNinja},
    {"Healer", &createHealer},
    {"Warrior", &createWarrior}
};



map<string,unique_ptr<Card> (*)()> Mtmchkin::TYPE_OF_CARD{
        {"Barfight",&createBarFight},
        {"Dragon",&createDragon},
        {"Gremlin",&createGremlin},
        {"Mana",&createMana},
        {"Merchant",&createMerchant},
        {"Treasure",&createTreasure},
        {"Well",&createWell},
        {"Witch",&createWitch}
};



Mtmchkin::Mtmchkin(const string &fileName):
m_roundsPlayed(0),
m_chosenCardIndex(0)
{
    printStartGameMessage();
    createDeck(fileName);
    createPlayers();
}



void Mtmchkin::playRound()
{
    m_roundsPlayed++;
    printRoundStartMessage(m_roundsPlayed);
    for (list<unique_ptr<Player>>::iterator player = m_activePlayers.begin(); player != m_activePlayers.end();)
    {
        printTurnStartMessage((*player)->getName());
        m_deckOfCards[m_chosenCardIndex]->applyEncounter(*(*player));

        if ((*player)->isWin())
        {
            unique_ptr<Player> temp=std::move(*player);
            player = m_activePlayers.erase(player);
            m_winnerPlayers.push_back(std::move(temp));

        }
        else if ((*player)->isLose()) {
            unique_ptr<Player> temp=std::move(*player);
            player = m_activePlayers.erase(player);
            m_loserPlayers.push_front(std::move(temp));
        }
        else
        {
            player++;
        }
        m_chosenCardIndex++;
        if (m_chosenCardIndex == m_numOfCards)
        {
            m_chosenCardIndex = 0;
        }
    }
    if(isGameOver())
    {
        printGameEndMessage();
    }
}



bool Mtmchkin::isGameOver() const
{
    return m_activePlayers.empty();
}



int Mtmchkin::getNumberOfRounds() const
{
    return m_roundsPlayed;
}



void Mtmchkin::createPlayers()
{
    createEmptyGroup();

    string nameAndJob,name,job;
    for(int i=0;i<m_numOfPlayers;i++)
    {
        printInsertPlayerMessage();
        std::cin>>name>>job;
        std::cin.clear();
        std::cin.get();
        while(!isValidPlayer(name,job))
        {
            std::cin>>name>>job;
            std::cin.clear();
            std::cin.get();
        }
        try
        {
            std::unique_ptr<Player> (*create)(const string&)=TYPE_OF_PLAYER[job];
            m_activePlayers.push_back(create(name));
        }
        catch(std::bad_alloc& e)
        {
            m_activePlayers.clear();
            m_deckOfCards.clear();
            throw FailedAllocatingPlayers();
        }
    }
}



void Mtmchkin::createDeck(const string &fileName)
{
    ifstream sorce(fileName);
    if (!sorce) {
        throw DeckFileNotFound();
    }
    int numOfCards = 0;
    int lineNum = 1;
    string className;
    while (std::getline(sorce, className)) {
        if (!CARD_TYPES.count(className)) {
            m_activePlayers.clear();
            m_deckOfCards.clear();
            throw DeckFileFormatError(lineNum);
        }
        try
        {
            std::unique_ptr<Card> (*create)()=TYPE_OF_CARD[className];
            m_deckOfCards.push_back(create());
            numOfCards++;
            lineNum++;
        }
        catch (std::bad_alloc& e)
        {
            m_activePlayers.clear();
            m_deckOfCards.clear();
            throw FailedAllocatingCards();
        }
    }
    if(numOfCards<MINIMUM_NUM_OF_CARDS)
    {
        m_activePlayers.clear();
        m_deckOfCards.clear();
        throw DeckFileInvalidSize();
    }
    m_numOfCards=numOfCards;
}



void printPlayersLeaderboard(int &startRanking, const std::list<std::unique_ptr<Player>> &playersList)
{
    for (const std::unique_ptr<Player> &player: playersList)
    {
        printPlayerLeaderBoard(startRanking, *player);
        startRanking++;
    }
}



void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int ranking = 1;

    printPlayersLeaderboard(ranking, m_winnerPlayers);
    printPlayersLeaderboard(ranking, m_activePlayers);
    printPlayersLeaderboard(ranking, m_loserPlayers);
}



void Mtmchkin::createEmptyGroup()
{
    printEnterTeamSizeMessage();
    string numberOfPlayers;
    std::getline (std::cin,numberOfPlayers);

    while(!Mtmchkin::isValidNumber(numberOfPlayers))
    {
        if(numberOfPlayers!=BACK_SPACE)
        {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
        }
        std::getline(std::cin,numberOfPlayers);
    }
    m_numOfPlayers= std::stoi(numberOfPlayers);
}



bool Mtmchkin::isValidNumber(std::string& number)
{
    if(number==BACK_SPACE)
    {
        return false;
    }
    int numberInCorrectFormat;
    try
    {
        numberInCorrectFormat= std::stoi(number);
    }
    catch(std::invalid_argument& e)
    {
        return false;
    }

    return (numberInCorrectFormat>=MINIMUM_NUM_OF_PLAYERS && numberInCorrectFormat<=MAXIMUM_NUM_OF_PLAYERS);
}



bool Mtmchkin::isValidPlayer(std::string& name,std::string& job)
{
   if(name.size()>MAX_NAME_LENGTH || !(name.find_first_not_of(LETTERS) == string::npos))
   {
       printInvalidName();
       return false;
   }
   if(!PLAYER_TYPES.count(job))
   {
       printInvalidClass();
       return false;
   }
    return true;
}

