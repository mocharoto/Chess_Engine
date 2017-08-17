#include "state.h"
#include "ui.h"

// Default state draw operation just draws the ui.
void State::draw() {
	uiManager.draw();
}

// Override to provide behavior.
void State::enter() { }
void State::pause() { }
void State::exit() { }
