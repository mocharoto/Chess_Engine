#ifndef CHESSSTATE_H
#define CHESSSTATE_H

#include <iostream>
#include "board.h"
#include "state.h"

class ChessState : public State {
	public:
	ChessState();

	// Loop methods
	StateChange update(int event) override;
	void draw() override;
	
	// Callbacks

	private:
	std::shared_ptr<board> Chessboard;

	int mouseClicks = 0;
	int xCursor = 0;
	int yCursor = 0;
	coord current = {0, 0};
	coord next = {0, 0};
	bool clicked = false;
	bool running = true;
	coord boardOffset{ 2, 5 };
};

#endif
