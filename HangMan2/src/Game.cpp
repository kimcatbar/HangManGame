#include "Game.h"

using namespace std;

#include <iostream>
#include <string>
#include <vector>

Game::Game()
{
	cout << "game class constructor\n";//sometimes I cout stuff for debugging and seeing what happens
	input = 'A';
	user_response.resize(0);
	end_game = false;
}

Game::Game(string word, char input)
{
	cout << "game class overloaded constructor.\n";
	setWord(word);
	setVector(input);
}

void Game::setWord(string word)
{
	this -> word = word;
	return;
}

void Game::setVector(char input)
{

    user_response.push_back(input);
	return;
}

bool Game::endGame()
{

	if(word.size() == user_response.size())
	{
    	end_game = true;
	}
	else
	{
    	end_game = false;
	}
	return end_game;
}

bool Game::getEndGame() const
{
	return end_game;
}

