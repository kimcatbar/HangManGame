#include "Letter.h"

using namespace std;

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
Letter::Letter()
{
    cout << "Letter Class Constructor is a GO!" << endl;
	checkForChar('H');
	checkLetter('A', "Boom");
	result = false;
	counter = 0;
}
void Letter::checkForChar(char input)
{
	if (isalpha(input) == false)
	{
    	cout << "Error, you must input a single character.\n";
    	cout << "Please enter a valid character.\n";
	}

	else if (isalpha(input) == 1 || isalpha(input) == 2)
	{
        checkLetter(input, "Boom");
	}
}

void Letter::checkLetter(char input, string word)
{
	for (int unsigned i = 0; i < word.size(); i++)
	{
    	//counter was creating an infinitely "true" loop by always counting up
    	//started making a game class to make a condition that would make the game end when the user won separate from the Letter class to not get too confusing hopefully
    	if(input == word[i])
    	{
        	result = true;
        	break;//returns true as soon as a match is found to fix the always returning false error
    	}
    	else
    	{
        	result = false;
    	}
	}
}
int Letter::getIndeces(char input, string word, int * indices)
{
    int size = 0;
    for ( int unsigned p = 0; p < word.size(); p++)
    {
        if(input == word[p])
        {
            indices[size] = p;
            size++;
        }
    }
    return size;
}
char Letter::getLetter() const
{
	return letter;
}

bool Letter::getResult() const
{
	return result;
}
string Letter::getWord() const
{
	return word;
}

