#ifndef LETTER_H
#define LETTER_H

#include "Letter.h"

#include <string>

using namespace std;
class Letter
{
public:
    Letter();
    //check if player input is in fact a char, or not.
    void checkForChar(char);
    //check if char is in certain index of string
    void checkLetter(char, string);
    //getters for dialogue in main
    int getIndeces(char, string, int *);
    bool getResult() const;
    char getLetter() const;
    string getWord() const;

private:
    //word player is attempting to guess
    string word;
    //user input of single char
    char letter;
    //counts the amount of times char is false
    //counter should be less than,or = to, amount of "limbs" the hangman has
    //if it reaches, let's say, 6 or 7 then game is over.
    //not sure how many "limbs" there will be
    int counter;
    //result for if the word matches or not to fix non-matching return type error
    bool result;
};


#endif // LETTER_H
