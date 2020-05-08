#pragma once

#include <iostream>
#include <vector>

using namespace std;

class board
{
public:
	board();
	~board();

private:
	vector<int> v;
	int dim;
};

board::board()
{
	
}

board::~board()
{
}
