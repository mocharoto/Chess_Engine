//Author: Srujan Kanteti
//Date Started: 9 August 2017.
//Purpose: The purpose of this file is to create a class that helps users
//         play the game in turns.

#include "board.h"
#include "pawn.h"
#include "knight.h"
#include "bishop.h"
#include "coord.h"

enum turn{ Black =0, White= 1 };

class game
{
  private:
    board Chessboard;
    turn CurrentPlayer;

  public:
    game();
    void start_game();
    bool current_checkmate();
};
