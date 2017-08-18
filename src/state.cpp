#include "state.h"
#include "BearLibTerminal.h"

// Default update does nothing.
StateChange State::update(int event) {

	return StateChange{ StateChange::Operation::None, "" };
}

// Default state draw operation just draws the ui.
void State::draw() {
	terminal_clear();
	uiManager.draw();
	terminal_refresh();
}

// Override to provide behavior.
void State::enter() { }
void State::pause() { }
void State::exit() { }
