//Author: Sean Brock
//Date Created: 12 August 2017
//File Description: UI elements.

#ifndef ELEMENT_H
#define ELEMENT_H

#include "coord.h"
#include "board.h"

// Drawing location prefernces for text and ui.
enum class Alignment {
	Centered,
	Right,
	Left
};

// UI element base class. To be handled by the ui class.
struct element
{
public:
	element() = default;
	element(coord newSize) : size(newSize) { }

	// Draws the element data to BearLibTerminal.
	virtual void draw(coord pos) = 0;

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
class BoardElement : public element
{
public:
	BoardElement() = delete;
	BoardElement(std::shared_ptr<board> newBoardRef)
		: element({boardSize::x, boardSize::y})
		, boardRef(newBoardRef)
	{ }

	// Inherited from element.
	void draw(coord pos) override;

private:
	// Const pointer. Used to draw the board.
	std::shared_ptr<board> boardRef;
};

// Formatted display of a text message.
// Ideally used as a splash screen or title.
class TitleElement : public element
{
public:
	TitleElement() = delete;
	// Custom colors available through blt: white, black, red, etc...
	TitleElement(std::string newMessage, std::string newColor, Alignment newAlignment)
		: element({int(newMessage.length()), 1})
		, message(newMessage)
		, color(newColor)
		, align(newAlignment) { }

	// Inherited from element.
	void draw(coord pos) override;

private:
	std::string message;
	std::string color;
	Alignment align;
};


#endif
