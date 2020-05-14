#include <iostream>
#include <fstream>
#include "Board_main.h"
#include "Game.h"
#include "Player.h"

using namespace std;


int main()
{
	Game game;

	cout << "************ Welcome To Scrabble Junior ************" << endl;

	cout << "Object Of The Game: " << endl;

	cout << "************" << endl;

	cout << endl << "Cover the game board lettes with matching letter tiles and collect ";

	cout << "the most scoring chips for completing words." << endl;

	vector<Player> Players = game.CreatePlayer();



}