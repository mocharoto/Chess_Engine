//Author: Julian Yi
//Date Created: 27 July 2017
//File Description: Header files for the King
#ifndef KING_H
#define KING_H

class King : public Pieces
{
	protected:
	public:
		void Check();
		void Checkmate();
}

#endif

