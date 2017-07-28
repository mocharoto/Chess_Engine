//Author: Julian Yi
//Date: 14 July 2017
//board functions


#include "board.h"



using namespace std;

board::board() { }

bool board::placePiece(std::string pieceName, int x, int y, board::Square ** Chessboard)
{
	bool flag = false;

	if (Chessboard[x][y].isOccupied != false && Chessboard[x][y].canMove == true)
	{
		Chessboard[x][y].isOccupied = true;
		Chessboard[x][y].canMove = false;
		Chessboard[x][y].pieceTag = pieceName;

		flag = true;
	}
	else
	{
		flag = false;
	}

	return flag;
}

board::Square board::initializeBoard(board::Square ** Chessboard)
{
	int Ascii = 65;
	string boardTag = "";

	for (int index = 0; index < board::sizeY; ++index)
	{
		for (int jindex = 0; jindex < board::sizeX; ++jindex)
		{
			boardTag = (char(Ascii));
			boardTag += to_string(jindex);

			Chessboard[index][jindex].isOccupied = true;
			Chessboard[index][jindex].canMove = true;
			//Chessboard[index]->tag = (char(Ascii) + '-' + char(index));
			Chessboard[index][jindex].tag = boardTag;
			Chessboard[index][jindex].pieceTag = "";
		}

		Ascii++;
	}
	return **Chessboard;
}

//created for testing purpose
void printBoard(board::Square **Chessboard)
{
	for (int index = 0; index < board::sizeY; ++index)
	{
		for (int jindex = 0; jindex < board::sizeX; ++jindex)
		{
			cout << Chessboard[index][jindex].tag;
		}

		cout << endl;
	}
}
