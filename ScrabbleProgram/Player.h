#pragma once

#include <iostream>
#include <vector>
#include "Pool.h"

using namespace std;

class Player
{
public:
	Player();
	~Player();

	string name;

	vector<char> hand;

	void CreateHand(vector<char>& hand);

private:

};

Player::Player()
{
}

Player::~Player()
{
}

void Player::CreateHand(vector<char>& hand)
{

}