//
// Created by nrhbv on 06/01/2023.
//

#ifndef EX4_MAIN_EXCEPTION_H
#define EX4_MAIN_EXCEPTION_H
#include <stdexcept>


/*
 * Exception for invalid file for the deck.
 *          this is an Invalid Argument exception type.
*/
class DeckFileNotFound:public std::invalid_argument
{
public:
    DeckFileNotFound():
            std::invalid_argument("Deck File Error: File not found")
    {}

    DeckFileNotFound(const DeckFileNotFound& eToCopy)=default;
    DeckFileNotFound& operator=(const DeckFileNotFound& e)=default;
    ~DeckFileNotFound()=default;
};



/*
 * Exception for invalid file format for the deck.
 *          this is an Invalid Argument exception type.
*/
class DeckFileFormatError:public std::invalid_argument
{
public:
    explicit DeckFileFormatError(int line):
            std::invalid_argument("Deck File Error: File format error in line "+ std::to_string(line))
    {}

    DeckFileFormatError(const DeckFileFormatError& eToCopy)=default;
    DeckFileFormatError& operator=(const DeckFileFormatError& e)=default;
    ~DeckFileFormatError()=default;
};



/*
 * Exception for invalid deck size.
 *          this is a Length Error exception type.
*/
class DeckFileInvalidSize:public std::length_error
{
public:
    DeckFileInvalidSize():
            std::length_error("Deck File Error: Deck size is invalid")
    {}

    DeckFileInvalidSize(const DeckFileInvalidSize& eToCopy)=default;
    DeckFileInvalidSize& operator=(const DeckFileInvalidSize& e)=default;
    ~DeckFileInvalidSize()=default;
};


/*
 * Exception for failing in creation of new players due to an allocation failure.
 *          this is a bad alloc exception type.
*/
class FailedAllocatingPlayers:public std::bad_alloc
{
public:
    FailedAllocatingPlayers()=default;
    const char * what() const throw() override
    {
        return "Allocation failed.No players created. All of Mtmchkin's fields had been successfully destroyed.";
    }
    FailedAllocatingPlayers(const FailedAllocatingPlayers& eToCopy)=default;
    ~FailedAllocatingPlayers()=default;
};




/*
 * Exception for failing in creation of new cards due to an allocation failure.
 *          this is a bad alloc exception type.
*/
class FailedAllocatingCards:public std::bad_alloc
{
public:
    FailedAllocatingCards()=default;
    const char * what() const throw() override
    {
        return "Allocation failed.No cards created.. All of Mtmchkin's fields had been successfully destroyed.";
    }
    FailedAllocatingCards(const FailedAllocatingCards& eToCopy)=default;
    ~FailedAllocatingCards()=default;
};



#endif //EX4_MAIN_EXCEPTION_H
