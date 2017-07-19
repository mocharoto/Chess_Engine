//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: Header File for the Knight Class
#pragma once

#include <iostream>
#include <string>
#include "pieces.h"

class Knight : public Pieces 
{
	private:
	public:
		void move(int newXCoordinate, int newyCoordinate);
} Knight;
