//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: Header file for the pawn class.
#pragma once

class Pawn : public Pieces 
{
	private:
	public:
		void move(int newXLocation, int newYLocation);
		void promote();
} Pawn;
