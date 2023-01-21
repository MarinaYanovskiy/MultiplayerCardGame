#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "../Mtmchkin.h"
#include "../Exception.h"
#include <algorithm>


using std::unique_ptr;
using std::cout;
using std::cerr;
using std::string;
using std::fstream;
using std::istringstream;
using std::vector;

#define MAX_ROUNDS 100


int main()
{
    string file="deck.txt";
    try
    {
        Mtmchkin game(file);
        while(!game.isGameOver()&&game.getNumberOfRounds()<MAX_ROUNDS)
        {
            game.playRound();
        }

        game.printLeaderBoard();
    }
    catch(DeckFileInvalidSize& e)
    {
        cout<<e.what();
    }
    catch(DeckFileFormatError& e)
    {
        cout<<e.what();
    }
    catch (DeckFileNotFound& e)
    {
        cout<<e.what();
    }
    catch (FailedAllocatingCards& e)
    {
        cout<<e.what();
    }
    catch (FailedAllocatingPlayers& e)
    {
        cout<<e.what();
    }
    return 0;
}
