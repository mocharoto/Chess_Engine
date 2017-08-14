#include <memory>
#include "ui.h"

void ui::setWindowSize(coord size) {

}

void ui::config(std::string settings) {

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
