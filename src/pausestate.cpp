#include "pausestate.h"
#include "BearLibTerminal.h"

PauseState::PauseState() { }

StateChange PauseState::update(int event) {
	StateChange nextState;

	switch (event) {
		case TK_ESCAPE:
			nextState.operation = StateChange::Operation::Pop;
			break;
		case TK_ENTER:
			//currentUIelement.activate();
			break;
		default: break;
	};

	return nextState;
}

void PauseState::draw() {

}
