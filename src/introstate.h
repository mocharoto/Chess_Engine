#ifndef INTROSTATE_H
#define INTROSTATE_H

#include <iostream>
#include "BearLibTerminal.h"
#include "state.h"
#include "element.h"

class IntroState : public State {
	public:
	IntroState();

	// Loop methods
	StateChange update(int event) override;

	// Callbacks
	void enter() override;

	void exit() override;
};

#endif
