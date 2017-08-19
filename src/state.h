#ifndef STATE_H
#define STATE_H

#include <string>
#include "ui.h"

struct StateChange {
	enum class Operation { None, Add, Pop, Change };

	StateChange() : operation(Operation::None), id("") { }
	StateChange(Operation newOp, std::string newId)
		: operation(newOp), id(newId) { }

	Operation operation;
	std::string id;
};

// State base class
class State {
	public:
	// Loop methods
	virtual StateChange update(int event);
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
