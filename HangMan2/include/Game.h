#ifndef GAME_H
#define GAME_H

using namespace std;

#include <vector>
#include <string>

class Game
{
private:
	char input;
	string word;
	vector<char> user_response;
	bool end_game;

public:
	Game();
	Game(string, char);
	void setWord(string word);
	void setVector(char input);
	char getVector();
	bool endGame();
	bool getEndGame() const;
};

#endif // GAME_H
