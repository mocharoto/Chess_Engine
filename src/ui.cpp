#include <memory>
#include <string>
#include <iostream>
#include "ui.h"
#include "BearLibTerminal.h"

coord ui::windowSize = { 0, 0 };

void ui::openWindow() {
	terminal_open();
}

void ui::setWindowSize(coord size) {
	windowSize = size;
}

void ui::config(std::string settings) {
	terminal_set(settings.c_str());
}

void ui::draw() {
	if (!elements.empty()) {
		for (auto& e : elements) {
			// Call the draw function of each element, at its respective position.
			e.elementPtr->draw(e.pos);
		}
	}
}

void ui::addElement(std::shared_ptr<element> newElement, coord pos) {
	elements.emplace_back(newElement, pos);
}

bool ui::removeElement(coord pos) {
	for (auto itr = elements.begin(); itr != elements.end();) {
		if (itr->pos == pos) {
			itr = elements.erase(itr);
			return true;
		} else {
			++itr;
		}
	}
	return false;
}
