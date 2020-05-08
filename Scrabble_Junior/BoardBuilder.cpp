#include <iostream>
#include "board.h"
#include "Tile.h"
#include <fstream>

using namespace std;


vector <string> TileWord(int x, int y);




int main()
{

	int dim_board;

	ifstream file("WORDS.txt"); //FILE COM AS PALAVRAS QUE O USER TEM A DISPOSIÇÃO

	if (file.is_open())
	{
		cout << "***** WELCOME TO SCRABBLE JUNIOR ******" << endl;

	}

	else cout << "The file that contains the dictionary could not open" << endl;

	


	




	return 0;
}






