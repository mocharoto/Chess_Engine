#include "introstate.h"

IntroState::IntroState() : State() {
	// Create title screen
	uiManager.addElement(
		std::make_shared<TitleElement>(
			"Chess Engine",
			"white",
			Alignment::Centered
		),
		{windowSize::x / 2, (windowSize::y / 2) - 5}
	);
	uiManager.addElement(
		std::make_shared<TitleElement>(
			"by Julian Yi, Sean Brock,",
			"grey",
			Alignment::Centered
		),
		{windowSize::x / 2, (windowSize::y / 2) - 3}
	);
	uiManager.addElement(
		std::make_shared<TitleElement>(
			"Simon Kim, and Consquigi", // hue
			"grey",
			Alignment::Centered
		),
		{windowSize::x / 2, (windowSize::y / 2) - 2}
	);
	uiManager.addElement(
		std::make_shared<TitleElement>(
			"Press Enter",
			"red",
			Alignment::Centered
		),
		{windowSize::x / 2, (windowSize::y / 2) + 1}
	);
}

StateChange IntroState::update(int event) {
	StateChange next; // default do nothing
	std::cout << "Intro state updated" << std::endl;
	if (event == TK_ENTER) {
		std::cout << "Chess State sent" << std::endl;
		next.operation = StateChange::Operation::Change;
		next.id = "ChessState";
	}

	return next;
}

void IntroState::enter() {
	std::cout << "IntroState entered." << std::endl;
}

void IntroState::exit() {
	std::cout << "IntroState exitted" << std::endl;
}
