#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

// State stack manager

#include <stack>
#include <memory>
#include <string>

class State;

class StateManager {
	public:
	void addState(std::string id);
	void popState();
	
	void update();
	void draw();

	bool empty() const;

	private:
	std::stack< std::shared_ptr<State> > states; 
};

}

#endif
