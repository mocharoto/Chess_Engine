#ifndef STATE_HPP
#define STATE_HPP

class ui;
struct StateChange;

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
