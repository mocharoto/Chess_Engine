#include <iostream>
#include "game.h"


//Function: Default constructors
//Description: This function initializes the game
game::game()
{
  // Set the current Player
  CurrentPlayer = White;

  // Init the board
	Chessboard.initializeBoard();

  // Add the White pawn
  for (int i = 0; i < 8; i++) {
		Chessboard.placePiece(PieceType::Pawn, {i, 1}, TeamColor::White);
	}

  //Add the Black pawn
  for (int i = 0; i < 8; i++) {
    Chessboard.placePiece(PieceType::Pawn, {i, 6}, TeamColor::Black);
  }

  // Add the other Pieces
	Chessboard.placePiece(PieceType::Rook, {0, 0}, TeamColor::White);
	Chessboard.placePiece(PieceType::Rook, {7, 0}, TeamColor::White);
	Chessboard.placePiece(PieceType::Knight, {1, 0}, TeamColor::White);
	Chessboard.placePiece(PieceType::Knight, {6, 0}, TeamColor::White);
	Chessboard.placePiece(PieceType::Bishop, {2, 0}, TeamColor::White);
	Chessboard.placePiece(PieceType::Bishop, {5, 0}, TeamColor::White);
	Chessboard.placePiece(PieceType::Queen, {3, 0}, TeamColor::White);
	Chessboard.placePiece(PieceType::King, { 4,0 }, TeamColor::White);
	Chessboard.placePiece(PieceType::Rook, {0, 7}, TeamColor::Black);
	Chessboard.placePiece(PieceType::Rook, {7, 7}, TeamColor::Black);
	Chessboard.placePiece(PieceType::Knight, {1, 7}, TeamColor::Black);
	Chessboard.placePiece(PieceType::Knight, {6, 7}, TeamColor::Black);
	Chessboard.placePiece(PieceType::Bishop, {2, 7}, TeamColor::Black);
	Chessboard.placePiece(PieceType::Bishop, {5, 7}, TeamColor::Black);
	Chessboard.placePiece(PieceType::Queen, {3, 7}, TeamColor::Black);
	Chessboard.placePiece(PieceType::King, { 4,7 }, TeamColor::Black);
}

//Function: start_game
//Description: This function starts the game with two players
void game::start_game()
{
    // This while loop runs until the a plyer is checkmated
    while (1) {


    }

}

//Function: current_checkmate
//Description: This function check to see if there are any checkmates
void game::current_checkmate()
{


}
