#pragma once

#include <iostream>
#include "Player.h"
#include "Pool.h"
#include "board_main.h"

using namespace std;

class Game
{
public:
	Game();
	~Game();

	vector<Player> CreatePlayer();

	vector<char> CreatePool();

	vector<char>	CreateHand();

	void	CreateBoard();

private:

};

Game::Game()
{
}

Game::~Game()
{
}

vector<Player> Game::CreatePlayer()
{



}