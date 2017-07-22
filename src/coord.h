//Author: Sean Brock
//Date Created: 22 July 2016
//File Description: Coord helper class for a 2d point.

#ifndef COORD_H
#define COORD_H

class coord
{
public:
  int x, y;

  coord();
  coord(int newX, int newY);

  // Adder and subtractor helpers.
  friend coord operator+(const coord& left, const coord& right);
  friend coord operator-(const coord& left, const coord& right);

};


#endif
