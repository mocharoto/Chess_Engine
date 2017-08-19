#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "state.h"

class PauseState : public State {
	public:
	PauseState();

	// Loop methods
	StateChange update(int event) override;
	void draw() override;

};

#endif
