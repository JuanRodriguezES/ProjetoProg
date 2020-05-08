#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class tile
{
public:
	tile();

	~tile();


private:

	char letter;

	int CoordX;

	int CoordY;

	bool marked; 

};

tile::tile()
{


}

tile::~tile()
{
}






