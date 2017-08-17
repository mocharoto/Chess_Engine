#include <iostream>
#include <exception>
#include "StateManager.hpp"
#include "State.hpp"

/* Uncomment when states have been defined
std::shared_ptr<State> idToState(std::string id) {
	if (id == "Game") {
	
	} else if (id == "Menu") {
	
	} // etc...
}
*/

void StateManager::addState(std::string id) {
	// states.push(idToState(id));
}

void StateManager::popState() {
	// Call exit on currect state
	auto statePtr = states.top();
	state_ptr->exit();

	// Remove current state
	try {
		states.pop();
	} catch (std::exception& e) {
		std::cerr << "E: Popping state: " << e.what() << std::endl;
	}
}

void StateManager::update() {
	auto statePtr = states.top();
	auto nextState = statePtr->update();

	State_Operation op = nextState.operation;
	std::string id = nextState.id;

	if (op == StateChange::Operation::None) {
		// Do nothing
	} else if (op == StateChange::Operation::Add) {
		addState(id);
	} else if (op == StateChange::Operation::Pop) {
		popState(id);
	}
}

void StateManager::draw() {
  auto statePtr = states.top();
  statePtr->draw();
}

bool StateManager::empty() const {
  return states.empty();
}
