#ifndef INTROSTATE_H
#define INTROSTATE_H

#include <iostream>
#include "BearLibTerminal.h"
#include "state.h"
#include "element.h"

class IntroState : public State {
	public:
	IntroState() : State() {
		auto title = std::make_shared<TitleElement>("Chess", "white", Alignment::Centered);
		uiManager.addElement(title, { windowSize::x / 2, windowSize::y / 2 - 5 });
	}

	// Loop methods
	inline StateChange update(int event) override {
		StateChange next; // default do nothing

		if (event == TK_ENTER) {
			next.operation = StateChange::Operation::Change;
			next.id = "IntroState";
		}

		return next;
	}

	inline void draw() override {

	}

	// Callbacks
	inline void enter() override {
		std::cout << "IntroState entered." << std::endl;
	}

	inline void exit() override {
		std::cout << "IntroState exitted" << std::endl;
	}
};

#endif
