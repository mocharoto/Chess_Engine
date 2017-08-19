//Author: Julian Yi
//Date Started: 14 July 2017, Friday.
//Purpose: This is a project to create a working chess engine and gui using C++.
//File: This is the main file.
#include <iostream>
#include "statemanager.h"
#include "BearLibTerminal.h"
#include "ui.h"

int main()
{
	std::string settings =
		"window:"
			"title='Chess',"
			"size='" + std::to_string(windowSize::x) + "x" + std::to_string(windowSize::y) + "';"
		"font: ./font/FSEX300.ttf,"
			"size=32x32;"
		"palette:"
			"whitepiece=#C2CCCF,"
			"blackpiece=#4D483C,"
			"whitetile=#02171F,"
			"blacktile=#000000;"
		"input:"
			"cursor-symbol = 0x1F,"
			"cursor-blink-rate = 500,"
			"precise-mouse = false,"
			"mouse-cursor = true,"
			"filter=[keyboard, mouse];"
	;

	// Setup the window.
	ui::openWindow();
	ui::config(settings);

	// Initialize game state to Intro.
	StateManager stateMan;
	stateMan.addState("IntroState");

	// Game loop.
	for (bool running = true; running == true;) {
		//std::cout << "Loop" << std::endl;
		auto event = terminal_read();

		// Global close with the window "X".
		if (event == TK_CLOSE) {
			break;
		}

		stateMan.update(event);
		stateMan.draw();
	}

	ui::closeWindow();
	
	return 0;
}
