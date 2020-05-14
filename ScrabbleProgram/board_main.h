#pragma once


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Color.h"
#include "tile.h"

using namespace std;

class Board
{
public:
	Board();
	~Board();
	void GetWords(ifstream& InputBoard);

	void WordVector(vector<vector<tile>>& v, string coordinates, char direction, string word);

	void board_built(vector<vector<tile>> boardvect);

private:

};

Board::Board()
{
}

Board::~Board()
{
}


void Board::GetWords(ifstream& InputBoard)
{
	int length, width;

	string	line, coordinates, word;

	char direction, separator;

	vector<vector<tile>> board_vector;


	getline(InputBoard, line);

	


	stringstream ss(line);

	ss >> length;

	ss >> separator;

	ss >> width;
	

	

	board_vector.resize(length, vector<tile>(width));

	ss.clear();
	

	while (getline(InputBoard, line))
	{
		
		stringstream is(line);

		
		if (line.empty())
		{
			break;
		}
		else
		{
			is >> coordinates;
			is >> direction;
			is >> word;
			WordVector(board_vector, coordinates, direction, word);
		}

	}

	board_built(board_vector);
	
}

void Board::WordVector(vector<vector<tile>>& v, string coordinates, char direction, string word)
{
	size_t x_coord = coordinates[0] - 'A';

	

	size_t y_coord = coordinates[1] - 'a';

	 
	size_t index = 0;



	switch (direction)
	{
		case 'h':
			
			for (size_t i = y_coord; i < word.size(); i++)
			{
				v[x_coord][i].ch = word[index];
				

			
				index++;
				
			}
			break;

		case 'v':
			index = 0;
			for (size_t i = x_coord; i < word.size(); i++)
			{
				v[i][y_coord].ch = word[index];
				index++;
			}
			break;

		default:
			break;
	}

}

void   Board::board_built(vector<vector<tile>> boardvect)
{
	vector<char> x_line, y_line;

	char char_x = 'a', char_y = 'A';

	for (size_t i = 0; i < boardvect[0].size() + 1; i++)
	{

		if (i == 0) x_line.push_back(' ');
		else
		{
			x_line.push_back(char_x);
			char_x++;
		}
	}

	for (size_t i = 0; i < boardvect.size(); i++)
	{
		y_line.push_back(char_y);
		char_y++;
	}
	for (size_t i = 0; i < x_line.size(); i++)
	{
		cout << setw(2) << x_line[i];
	}

	cout << endl;


	for (int i = 0; i < boardvect.size(); i++)
	{
		cout << setw(2) << y_line[i];
		for (int j = 0; j < boardvect[i].size(); j++)
		{
			setcolor(0, 15);
			cout << setw(2) << boardvect[i][j].ch;
		}

		setcolor(15, 0);

		cout << endl;
	}

	
}

