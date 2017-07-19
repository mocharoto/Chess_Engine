//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: Header file for Bishop class
#pragma once

#include <iostream>
#include <string>
#include "piece.h"

class Bishop : public Pieces
{
	private:
	public:
		void move(int newXCoordinate, int newyCoordinate);
} Bishop;
