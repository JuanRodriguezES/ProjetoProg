#include <iostream>
#include <vector> 
#include <string>
#include <fstream>
#include "board.h"

using namespace std;
int main()
{
	ifstream	file_words("WORDS.txt");

	ofstream	OutFile("Board.txt");

	board	BuildBoard;


	int lenght, width, i, counter = 0;
	string more, word, orientation, coordinates;
	bool validSize, validWord, validOrientation, validPosition, validMore;
	vector<vector<char>> boardvect;
	validSize = false;
	do
	{
		cout << "Introduce the lenght of the board: ";
		cin >> lenght;
		cout << "Introduce the width of the board: ";
		cin >> width;
		if ((lenght <= 20) && (lenght > 0) && (width <= 20) && (width > 0))
			validSize = true;
		if ((lenght > 20) | (width > 20))
			cout << "[INVALID INPUT]: The maximum size allowed is 20x20!" << endl;
		if ((lenght <= 0) | (width <= 0))
			cout << "[INVTALID INPUT]: The board size needs to be positive!" << endl;
	} while (validSize == false);
	boardvect.resize(lenght);
	for (i = 0; i < lenght; i++)
		boardvect[i].resize(width, ' ');

	if (OutFile.is_open())
	{
		OutFile << lenght << " x " << width << endl;
	}
	else
	{
		cout << "The OutFile didn't open" << endl;
	}

	//falta adicionar o tamanho ao ficheiro BOARD.TXT
	do
	{
		cout << "Introduce the word: ";
		cin >> word;

		while (!(BuildBoard.CheckWord(file_words, word)))
		{
			cout << "The word introduced is not in the Dictionary" << endl << "Enter another word: ";
			cin >> word;
		}

		
		//verificar se word está em WORD.TXT
		validPosition = false;
		do
		{
			cout << "Enter the position you want to put the first letter of the word (lenght: A to " << (char)(65 + lenght - 1) << ";width: a to " << (char)(97 + width - 1) << "): ";
			cin >> coordinates;
			if ((coordinates[0] >= 'A') && (coordinates[0] <= (char)(65 + lenght - 1)) && (coordinates[1] >= 'a') && (coordinates[1] <= (char)(97 + width - 1)))
				validPosition = true;
			else
				cout << "[ERROR]: The coordinates you introduced are not valid!" << endl;
		} while (validPosition == false);
		validOrientation = false;
		do
		{
			cout << "Introduce the orientation you want word to be placed (h or v): ";
			cin >> orientation;
			if ((orientation != "h") && (orientation != "v"))
				cout << "[INVALID INPUT]: Orientation not valid!" << endl;
			if (((((int)coordinates[0] - 65 + (int)word.size()) > lenght) && (orientation == "v")) | ((((int)coordinates[1] - 97 + (int)word.size()) > width) && (orientation == "h")))
				cout << "[ERROR]: That word at that position does not fit on the board!" << endl;
			else
				validOrientation = true;
		} while (validOrientation == false);
		validWord = true;
		for (i = 0; i < (int)word.size(); i++)
		{
			if (((orientation == "v") && (boardvect[i + (int)coordinates[0] - 65][(int)coordinates[1] - 97] != ' ') && (word[i] != boardvect[i + (int)coordinates[0] - 65][(int)coordinates[1] - 97])) |
				((orientation == "h") && (boardvect[(int)coordinates[0] - 65][i + (int)coordinates[1] - 97] != ' ') && (word[i] != boardvect[(int)coordinates[0] - 65][i + (int)coordinates[1] - 97])))
			{
				cout << "[ERROR]: That word can't be placed on the board at that position because it intersects another incorrectly!" << endl;
				validWord = false;
				break;
			}
		}
		if (validWord == true)
		{
			for (i = 0; i < (int)word.size(); i++)
			{
				if (orientation == "v")
					boardvect[i + (int)coordinates[0] - 65][(int)coordinates[1] - 97] = word[i];
				else
					boardvect[(int)coordinates[0] - 65][i + (int)coordinates[1] - 97] = word[i];
			}//falta colocar coordenadas e palavras no ficheiro BOARD.TXT

			OutFile << coordinates << "  " << orientation << "  " << word << endl;

			validMore = true;
			do
			{
				cout << "Do you want to introduce one more words?(yes or no)" << endl;
				cin >> more;
				if ((more != "yes") & (more != "no")) {
					cout << "[INVALID ANSWER]: You must insert 'yes' or 'no'!" << endl;
					validMore = false;
				}
			} while (validMore == false);
		}
	} while ((more == "yes") | (validWord == false));

	OutFile << endl << endl;
	BuildBoard.board_file(OutFile, boardvect);
	//2D BOARD INTO FILE
	OutFile.close();
}






