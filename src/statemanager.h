#ifndef STATEMANAGER_H
#define STATEMANAGER_H

// State stack manager

#include <stack>
#include <memory>
#include <string>

class State;

class StateManager {
	public:
	void addState(std::string id);
	void popState();
	void changeState(std::string id);

	void update(int event);
	void draw();

	bool empty() const;

	private:
	std::stack< std::shared_ptr<State> > states;
};

#endif
