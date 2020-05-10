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
	void	BoardBuilter(vector<vector<tile>> &v, const int dim);
	bool	BoardInsertWord(string word, vector<vector<tile>>&v , char direction, char x, char y);

private:
};

board::board()
{
	
}

board::~board()
{
}

void board::BoardBuilter(vector<vector<tile>>& v, const int dim)
{
	char x_line = 'a';
	char y_line = 'A';

	tile	tile1;

	tile1.letter = ' ';

	for (size_t i = 0; i < dim; i++) 
	{
		v.push_back(vector<tile>());
		for (size_t j = 0; j < dim; j++)
		{
			if (j == 0 && i != 0)
			{
				tile1.letter = y_line;
				v[i].push_back(tile1);
			}
			if (i == 0 && j == 0)
			{
				v[i].push_back(tile1);
			}
			else if (i == 0)
			{
				tile1.letter = x_line;
				v[i].push_back(tile1);
			}
			else
			{
				v[i].push_back(tile1);
			}


			x_line++;
		
		}

		y_line++;

	}
}

bool board::BoardInsertWord(string word, vector<vector<tile>>& v, char direction, char x, char y)
{
	//FUNÇÃO DE INSERÇÃO DE WORD E VERIFICAÇÃO DE PREENCHIMENTO




}
