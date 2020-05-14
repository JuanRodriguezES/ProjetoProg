#include <iostream>
#include <fstream>
#include "Board_main.h"

using namespace std;


int main()
{
	Board board;

	ifstream myfile("C:/Users/sjoao/source/repos/ProjetoProg/Scrabble_Junior/Board.txt");

	if (myfile.is_open())
	{

		board.GetWords(myfile);
	}
	else
		cout << "the file did not open" << endl;

	

}