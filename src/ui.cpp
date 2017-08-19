#include <memory>
#include <string>
#include <iostream>
#include "ui.h"
#include "BearLibTerminal.h"

coord ui::windowSize = { 0, 0 };

void ui::openWindow() {
	terminal_open();
	terminal_refresh();
}

void ui::closeWindow() {
	terminal_close();
}

void ui::setWindowSize(coord size) {
	windowSize = size;
}

void ui::config(std::string settings) {
	terminal_set(settings.c_str());
}

void ui::draw() {
	if (!elements.empty()) {
		//terminal_clear();
		for (auto& e : elements) {
			// Call the draw function of each element, at its respective position.
			e.elementPtr->draw(e.pos);
		}
		//terminal_refresh();
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

void ui::activateElement(coord elementPos, coord activatedPos) {
	// Find an element matching elementPos and activate it with the relative position.
	for (auto& e : elements) {
		if (e.pos == elementPos) {
			e.elementPtr->activate(activatedPos - elementPos);
		}
	}
}

void ui::clear() {
	elements.clear();
}
