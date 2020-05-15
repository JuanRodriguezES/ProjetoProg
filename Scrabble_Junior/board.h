#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class board
{
public:
	board();
	~board();
    bool CheckWord(ifstream& Inputfile, string search);
    void board_file(ofstream& Outputfile, vector<vector<char>> boardvect);

private:
};

board::board()
{
	
}

board::~board()
{
}

bool    board:: CheckWord(ifstream& Inputfile, string search)
{



    int offset;
    string line;
    

    if (Inputfile.is_open())
    {
        while (!Inputfile.eof())
        {
            getline(Inputfile, line);
            if ((offset = line.find(search, 0)) != string::npos)
            {
                Inputfile.seekg(ios::beg);
                return true;

            }
        }

        Inputfile.seekg(ios::beg);

        return false;
     
    }
    else
        cout << "Unable to open this file." << endl;

    
}
void    board::board_file(ofstream& Outputfile, vector<vector<char>> boardvect)
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
        Outputfile << setw(2) << x_line[i];
    }
    
    Outputfile << endl;
    
    
    if (Outputfile.is_open())
    {
        for (int i = 0; i < boardvect.size(); i++)
        {
            Outputfile << setw(2) << y_line[i];
            for (int j = 0; j < boardvect[i].size(); j++)
            {
                Outputfile << setw(2) << boardvect[i][j];
            }
            
            Outputfile << endl;
        }

    }
}