#ifndef STATE_MANAGER_HPP
#define STATE_MANAGER_HPP

// State stack manager

#include <stack>
#include <memory>
#include <string>

class State;

class State_Manager {
	public:
	void add_state(std::string id);
	void pop_state();
	void change_state(std::string id); // Similar to a pop then add.
	
	void update();
	void draw();

	bool empty() const;

	private:
	std::stack< std::shared_ptr<state> > states; 
};

}

#endif
