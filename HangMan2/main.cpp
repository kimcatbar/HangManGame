#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include "Letter.h"
#include "Game.h"
using namespace std;

int main()
{
    //our GAME + CLASS type variables
    Letter letter;
	Game win;
	char guess = '1';
	int wrong_guess = 0;
	ifstream textfile;
	vector<string> words;
	bool slots_correct[30];
	bool did_win = false;

	textfile.open("./xfile.txt");

	if (textfile.fail())
        {
            cout << "Error: input file open failed.\n";
            exit(1);
        }
    while(!textfile.eof())
    {
        string str;

        textfile >> str;
        words.push_back(str);
        //cout << words.size();
    }
    textfile.close();

    srand(time(NULL));
    int index = rand() % words.size();
    //game
    win.setWord(words[index]);

	//SFML window
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(  desktopMode.width,
                                          desktopMode.height,
                                          desktopMode.bitsPerPixel),
                            "HangMan",
                            sf::Style::Fullscreen);
                            window.setVerticalSyncEnabled (true);
                            window.setKeyRepeatEnabled(false);

    //Title screen
    sf::Font font, font2;
    if(!font.loadFromFile("./westerntext.ttf"))
        {std::cerr << "Error loading font.\n";
        return -2;
        }
    sf::Text mytext, start, input, endgame, letters[30], winwin;
    mytext.setFont(font);
    mytext.setCharacterSize(100);
    mytext.setColor(sf::Color::Black);
    mytext.setPosition(250, 70);
    mytext.setString("HangMan");
    start.setFont(font);
    start.setCharacterSize(35);
    start.setColor(sf::Color::Black);
    start.setPosition(50, 300);
    start.setString("Enter a letter :");
    input.setFont(font);
    input.setCharacterSize(25);
     if(!font2.loadFromFile("./typewriter.otf"))
        {std::cerr << "Error loading font.\n";
        return -2;
        }
    for( int i = 0; i < words[index].size(); i++)
    {
        //letters[i] index of word being guessed
        letters[i].setFont(font2);
        letters[i].setCharacterSize(70);
        letters[i].setColor(sf::Color::Black);
        letters[i].setPosition(10 + (i * 75), 650);
        letters[i].setString("_");
        slots_correct[i] = false;
    }
    //noose and what not

        sf::RectangleShape base(sf::Vector2f(350,10));
        base.setFillColor(sf::Color::Black);
        base.setPosition(sf::Vector2f(900,700));
        sf::RectangleShape pole(sf::Vector2f(450,10));
        pole.setFillColor(sf::Color::Black);
        pole.setRotation(270);
        pole.setPosition(900,700);
        sf::RectangleShape pole2(sf::Vector2f(175,10));
        pole2.setFillColor(sf::Color::Black);
        pole2.setPosition(900,250);
        sf::RectangleShape noose1(sf::Vector2f(80,10));
        noose1.setFillColor(sf::Color::Black);
        noose1.setRotation(90);
        noose1.setPosition(1080,250);

        sf::CircleShape head(50.f);
        head.setFillColor(sf::Color::Red);
        head.setOutlineThickness(10.f);
        head.setOutlineColor(sf::Color::Black);
        head.setPosition(1025,300);

        sf::RectangleShape torso(sf::Vector2f(135,10));
        torso.setRotation(90);
        torso.setFillColor(sf::Color::Black);
        torso.setPosition(1075,400);

        sf::RectangleShape left_leg(sf::Vector2f(120,10));
        left_leg.setRotation(135);
        left_leg.setFillColor(sf::Color::Black);
        left_leg.setPosition(1075,535);

        sf::RectangleShape right_leg(sf::Vector2f(120,10));
        right_leg.setRotation(45);
        right_leg.setFillColor(sf::Color::Black);
        right_leg.setPosition(1075,535);

        sf::RectangleShape left_arm(sf::Vector2f(120,10));
        left_arm.setRotation(135);
        left_arm.setFillColor(sf::Color::Black);
        left_arm.setPosition(1075,410);

        sf::RectangleShape right_arm(sf::Vector2f(120,10));
        right_arm.setRotation(45);
        right_arm.setFillColor(sf::Color::Black);
        right_arm.setPosition(1075,410);






    /// Flags for key pressed
    bool upFlag=false;
    bool downFlag=false;
    bool leftFlag=false;
    bool rightFlag=false;



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
                 if (event.type == sf::Event::KeyPressed)
                {
                    switch (event.key.code)
                        {
                        //When player presses key, it is stored in guess variable
                    //case sf::Keyboard::Return:
                        case sf::Keyboard::A:
                                guess = 'a';
                                break;
                        case sf::Keyboard::B:
                                guess = 'b';
                                break;
                         case sf::Keyboard::C:
                                guess = 'c';
                                break;
                        case sf::Keyboard::D:
                                guess = 'd';
                                break;
                        case sf::Keyboard::E:
                                guess = 'e';
                                break;
                        case sf::Keyboard::F:
                                guess = 'f';
                                break;
                        case sf::Keyboard::G:
                                guess = 'g';
                                break;
                        case sf::Keyboard::H:
                                guess = 'h';
                                break;
                        case sf::Keyboard::I:
                                guess = 'i';
                                break;
                        case sf::Keyboard::J:
                                guess = 'j';
                                break;
                        case sf::Keyboard::K:
                                guess = 'k';
                                break;
                        case sf::Keyboard::L:
                                guess = 'l';
                                break;
                        case sf::Keyboard::M:
                                guess = 'm';
                                break;
                        case sf::Keyboard::N:
                                guess = 'n';
                                break;
                        case sf::Keyboard::O:
                                guess = 'o';
                                break;
                        case sf::Keyboard::P:
                                guess = 'p';
                                break;
                        case sf::Keyboard::Q:
                                guess = 'q';
                                break;
                        case sf::Keyboard::R:
                                guess = 'r';
                                break;
                        case sf::Keyboard::S:
                                guess = 's';
                                break;
                        case sf::Keyboard::T:
                                guess = 't';
                                break;
                        case sf::Keyboard::U:
                                guess = 'u';
                                break;
                        case sf::Keyboard::V:
                                guess = 'v';
                                break;
                        case sf::Keyboard::W:
                                guess = 'w';
                                break;
                        case sf::Keyboard::X:
                                guess = 'x';
                                break;
                        case sf::Keyboard::Y:
                                guess = 'y';
                                break;
                        case sf::Keyboard::Z:
                                guess = 'z';
                                break;
                        case sf::Keyboard::Escape:
                            window.close();
                                break;
                    /// Process the up, down, left and right keys
                        case sf::Keyboard::Up:
                            upFlag=true;
                                break;
                        case sf::Keyboard::Down:
                            downFlag=true;
                                break;
                        case sf::Keyboard::Left:
                            leftFlag=true;
                                break;
                        case sf::Keyboard::Right:
                            rightFlag=true;
                                break;
                        default:
                                break;

                        }

                        if(wrong_guess == 10)
                            {
                                endgame.setFont(font);
                                endgame.setCharacterSize(70);
                                endgame.setColor(sf::Color::Green);
                                endgame.setPosition(50, 400);
                                input.setString("");
                                endgame.setString("You dead!");
                            }
                         else if (guess != '1' && did_win == false)
                            {
                                //letter
                                letter.checkLetter(guess, words[index]);
                                int indices[30];
                                int size = letter.getIndeces(guess, words[index], indices);
                                //game
                                win.setVector(guess);
                                if( size > 0)
                                {
                                input.setColor(sf::Color::White);
                                input.setPosition(50, 400);
                                char str[20] = " is in the word!";
                                for ( int i = 19; i > 0; i--)
                                {
                                    str[i] = str[i - 1];
                                }
                                str[0] = guess;
                                input.setString(str);
                                for (int k = 0; k < size; k++)
                                {
                                    char stri[5] = "_";
                                    stri[0] = guess;
                                    letters[indices[k]].setString(stri);
                                    slots_correct[indices[k]] = true;
                                }


                                }
                                else
                                {
                                input.setColor(sf::Color::Yellow);
                                input.setPosition(50, 400);
                                char str[25] = " is NOT in the word!";
                                for ( int i = 24; i > 0; i--)
                                {
                                    str[i] = str[i - 1];
                                }
                                str[0] = guess;
                                input.setString(str);
                                wrong_guess++;
                                }
                                did_win = true;
                                for (int d = 0; d < words[index].size(); d++)
                                {
                                    if (slots_correct[d] == false)
                                    {
                                        did_win = false;
                                        break;
                                    }
                                }
                                if(did_win)
                                {
                                winwin.setFont(font);
                                winwin.setColor(sf::Color::White);
                                winwin.setString("You win!");
                                winwin.setPosition(50,500);
                                }



                            }

                }

        }

        window.clear(sf::Color::Red);


        for (int a = 0; a < words[index].size(); a++)
        {
            window.draw(letters[a]);
        }
        window.draw(mytext);
        window.draw(endgame);
        window.draw(input);
        window.draw(start);
        window.draw(base);
        window.draw(pole);
        window.draw(pole2);
        window.draw(noose1);
        if(wrong_guess > 0)
        {
            window.draw(head);
        }
        if(wrong_guess > 2)
        {
            window.draw(torso);
        }
        if(wrong_guess > 4)
        {
            window.draw(left_leg);
        }
        if(wrong_guess > 6)
        {
            window.draw(right_leg);
        }
        if(wrong_guess > 8)
        {
            window.draw(right_arm);
        }
        if(wrong_guess == 10)
        {
            window.draw(left_arm);
        }
        window.draw(winwin);
        window.display();
    }
return  0;

}







