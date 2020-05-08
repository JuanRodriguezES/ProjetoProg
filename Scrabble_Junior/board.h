#pragma once

#include <iostream>
#include <vector>
#include "Tile.h"

using namespace std;

class board
{
public:
	board();
	~board();
	vector<tile> BoardBuilter(vector<tile> v, int dim);
	vector<tile> BoardInsertWord(string word, vector<tile> v);

private:
	vector<tile> v;
	int dim = 0;
};

board::board()
{
	
}

board::~board()
{
}
