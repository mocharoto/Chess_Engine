#ifndef STATE_MANAGER_HPP
#define STATE_MANAGER_HPP

// State stack manager

#include <stack>
#include <memory>
#include <string>

class State;

class State_Manager {
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
