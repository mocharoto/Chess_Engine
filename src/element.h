//Author: Sean Brock
//Date Created: 12 August 2017
//File Description: UI elements.

#ifndef ELEMENT_H
#define ELEMENT_H

#include "coord.h"
#include "board.h"

// UI element base class. To be handled by the ui class.
struct element
{
public:
	element() = default;
	element(coord newSize) : size(newSize) { }

	// Draws the element data to BearLibTerminal.
	virtual void draw() = 0;

	// Does nothing unless overidden. Use for clickable/selectable elements.
	inline virtual void activate(coord pos) { }

	inline void resize(coord newSize)
	{
		size = newSize;
	}

	inline const coord& getSize() const
	{
		return size;
	}

protected:
	coord size;
};

// Board UI. Not technically ui, as it won't be interacted with from here.
// Only UI for drawing purposes.
class boardElement : public element
{
public:
	boardElement() = delete;
	boardElement(const board* newBoardRef) : element({boardSize::x, boardSize::y}) { };

	// Inherited from element.
	void draw();

private:
	// Const pointer. Used to draw the board.
	const board* boardRef;
};

#endif
