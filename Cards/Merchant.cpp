//
// Created by Shirah Hassan on 1/12/23.
//

#include "Merchant.h"

std::string Merchant::getType() const
{
    return "Merchant";
}



void Merchant::applyEncounter(Player &player) const
{
    int userInput;
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());

    while (true)
    {
        std::string str;
        getline(std::cin, str);
        if(isValidInput(str))
        {
            userInput= std::stoi(str);
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



bool Merchant::isValidInput(std::string str)
{
    if (str.length() == 1)
    {
        try
        {
            std::size_t pos;
            int userInput = std::stoi(str, &pos);
            if (userInput == LEAVE_CMD || userInput == HEALTH_POTION_CMD || userInput == FORCE_BOOST_CMD)
            {
                return true;
            }
        }
        catch (const std::invalid_argument &ex)
        {
        }
        catch (const std::out_of_range &ex)
        {
        }
    }
    return false;
}



std::unique_ptr<Card> createMerchant()
{
    Merchant* merPtr=new Merchant();
    std::unique_ptr<Card> merchant(merPtr);
    return merchant;
}
