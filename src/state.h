#ifndef STATE_HPP
#define STATE_HPP

class ui;

enum class StateOperation { None, Add, Change, Pop };
using StateChange = std::pair<State_Operation, std::string>;

// State base class
class State {
	public:
	// Loop methods
	virtual StateChange update() = 0;
	virtual void draw();

	// Callback methods
	virtual void enter();
	virtual void pause(); 
	virtual void exit();

	protected:
	State() = default;
	
	ui uiManager;
};

#endif
