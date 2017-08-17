#include "state.h"
#include "ui.h"

// Default state draw operation just draws the ui.
void State::draw() {
	uiManager.draw();
}
