//Author: Julian Yi
//Date: 14 July 2017
//board functions


#include "board.h"

#define sizeY 8
#define sizeX 8

using namespace std;
Square initializeBoard(Square **Chessboard)
{
	int Ascii = 65;
	string boardTag = "";

	for (int index = 0; index < sizeY; ++index)
	{
		for (int jindex = 0; jindex < sizeX; ++jindex)
		{	
			boardTag = (char(Ascii));
			boardTag += to_string(jindex);

			Chessboard[index][jindex].isOccupied = false;
			Chessboard[index][jindex].canMove = false;
			//Chessboard[index]->tag = (char(Ascii) + '-' + char(index));
			Chessboard[index][jindex].tag = boardTag;
		}

		Ascii++;
	}


	return **Chessboard;
}

//created for testing purpose
void printBoard(Square **Chessboard)
{
	for (int index = 0; index < sizeY; ++index)
	{
		for (int jindex = 0; jindex < sizeX; ++jindex)
		{
			cout << Chessboard[index][jindex].tag;
		}

		cout << endl;
	}
}


int test() {


	//allocate 2d memory for the squares
	Square **board = new Square*[sizeY];
	
	for (int index = 0; index < sizeY; ++index)
	{
		board[index] = new Square[sizeX];
	}
	
	initializeBoard(board);
	printBoard(board);

	//cleanup
	for (int index = 0; index < sizeY; ++index)
	{
		delete [] board[index];
	}
	
	delete [] board;

	return 0;
}



