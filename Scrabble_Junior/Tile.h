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

	vector<string> TileWords(int CoordX, int CoordY);

	


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



vector<string> TileWords(int CoordX, int CoordY)
{

}


