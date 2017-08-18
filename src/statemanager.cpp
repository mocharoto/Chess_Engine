#include <iostream>
#include <exception>
#include "statemanager.h"
#include "state.h"
#include "introstate.h"


std::shared_ptr<State> idToState(std::string id) {
	std::shared_ptr<State> next;
	if (id == "IntroState") {
		next = std::make_shared<IntroState>();
	} else {
		std::cout << "E: Setting incorrect id " << id << " to IntroState" << std::endl;
		next = std::make_shared<IntroState>();
	}
	return next;
}

void StateManager::addState(std::string id) {
	states.push(idToState(id));
}

void StateManager::popState() {
	// Call exit on currect state
	auto statePtr = states.top();
	statePtr->exit();

	// Remove current state
	try {
		states.pop();
	} catch (std::exception& e) {
		std::cerr << "E: Popping state: " << e.what() << std::endl;
	}
}

void StateManager::changeState(std::string id) {
	popState();
	addState(id);
}

void StateManager::update(int event) {
	auto statePtr = states.top();
	auto nextState = statePtr->update(event);

	StateChange::Operation op = nextState.operation;
	std::string id = nextState.id;

	if (op == StateChange::Operation::None) {
		// Do nothing
	} else if (op == StateChange::Operation::Add) {
		addState(id);
	} else if (op == StateChange::Operation::Pop) {
		popState();
	}
}

void StateManager::draw() {
  auto statePtr = states.top();
  statePtr->draw();
}

bool StateManager::empty() const {
  return states.empty();
}
