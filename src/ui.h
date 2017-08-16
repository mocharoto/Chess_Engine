//Author: Sean Brock
//Date Created: 11 August 2017
//File Description: Abstraction for interface elements in BearLibTerminal.

#ifndef UI_H
#define UI_H

#include <string>
#include <vector>
#include <utility>
#include <memory>
#include "element.h"

namespace windowSize {
		static constexpr int x = 46;
		static constexpr int y = 24;
}

class ui
{
public:
	ui() = default;

	//// Window creation and Config ////

	// Opens the terminal window.
	static void openWindow();

	// Changes window size for the UI elements.
	// Needs to be accurately set, as the UI elements will change size/format.
	static void setWindowSize(coord size);

	// Calls BearLibTerminal terminal_set()
	static void config(std::string settings);

	//// Window layout ////

	// Adds an element.
	void addElement(std::shared_ptr<element> newElement, coord pos);

	// Removes an element. Returns if an element was found and removed.
	bool removeElement(coord pos);

	//// Draw logic ////

	// Draws all ui elements.
	void draw();

	//// UI element management ////

	// Clears UI element list, destroying all single referenced element shared pointers.
	void clear();

private:
	// Attaches a position to a ui element.
	struct elementWrapper
	{
		elementWrapper(std::shared_ptr<element> newElementPtr, coord newPos)
			: elementPtr(newElementPtr), pos(newPos)
			{ }

		std::shared_ptr<element> elementPtr;
		coord pos;
	};

	// List of ui elements and their locations.
	std::vector<elementWrapper> elements;
	static coord windowSize;
};

#endif
