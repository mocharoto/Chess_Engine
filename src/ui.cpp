#include <memory>
#include "ui.h"

void ui::setWindowSize(coord size) {

}

void ui::config(std::string settings) {

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
