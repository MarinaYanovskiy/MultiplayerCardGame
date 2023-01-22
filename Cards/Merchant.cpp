//
// Created by Shirah Hassan on 1/12/23.
//

#include "Merchant.h"
Merchant::Merchant():
        Card("Merchant")
{}



void Merchant::applyEncounter(Player &player) const
{
    int userInput;
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());

    while (true)
    {
        std::string input;
        getline(std::cin, input);
        if(isValidInput(input))
        {
            userInput= std::stoi(input);
            break;
        }
        printInvalidInput();
    }

    int cost = 0; // if input is LEAVE_CMD, the cost should be 0.

    if (userInput == HEALTH_POTION_CMD)
    {
        if (player.pay(HEALTH_PRICE))
        {
            player.heal(BOOST);
            cost = HEALTH_PRICE;
        }
        else
        {
            printMerchantInsufficientCoins(std::cout);
        }
    }
    else if (userInput == FORCE_BOOST_CMD)
    {
        if (player.pay(FORCE_PRICE))
        {
            player.buff(BOOST);
            cost = FORCE_PRICE;
        }
        else
        {
            printMerchantInsufficientCoins(std::cout);
        }
    }
    printMerchantSummary(std::cout, player.getName(), userInput, cost);
}



bool Merchant::isValidInput(const std::string& input)
{
    if (input.length() == 1)
    {
        try
        {
            std::size_t pos;
            int userInput = std::stoi(input, &pos);
            if (userInput == LEAVE_CMD || userInput == HEALTH_POTION_CMD || userInput == FORCE_BOOST_CMD)
            {
                return true;
            }
        }
        catch (...)
        {
        }
    }
    return false;
}



std::unique_ptr<Card> createMerchant()
{
    Merchant* merchantPtr=new Merchant();
    std::unique_ptr<Card> merchant(merchantPtr);
    return merchant;
}
