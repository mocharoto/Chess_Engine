#include "coord.h"

coord::coord() : x(0), y(0) { }

coord::coord(int newX, int newY) : x(newX), y(newY) { }

coord coord::swap()
{
  return coord{ y, x };
}

bool operator==(const coord& left, const coord& right)
{
	return left.x == right.x && left.y == right.y;
}

coord operator+(const coord& left, const coord& right)
{
  coord result;
  result.x = left.x + right.x;
  result.y = left.y + right.y;
  return result;
}

coord operator-(const coord& left, const coord& right)
{
  coord result;
  result.x = left.x - right.x;
  result.y = left.y - right.y;
  return result;
}
