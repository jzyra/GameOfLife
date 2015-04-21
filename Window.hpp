/*!
* \file Window.hpp
* \brief Window class.
* \author Jeremy ZYRA
*/
#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <iostream>
#include "Config.hpp"
#include "GameOfLife.hpp"

#define BPP 32

using namespace std;

class Window {

	public:
	/*!
		* \brief Window Constructor.
		Window class's constructor.
		* \param configuration object.
	*/
	Window(const Config &config);
	/*!
		* \brief Window Destructor.
		Window class's destructor.
	*/
	~Window();
	/*!
		* \brief Run cellular automaton.
	*/
	void run();
	/*!
		* \brief Draw cellular automaton in window.
	*/
	void draw();

	private:
	GameOfLife *_gameOfLife;
	int _width;
	int _height;
	int _nbX;
	int _nbY;
	SDL_Surface *_surface;
	/*!
		* \brief Manage SDL events.
	*/
	void event();

};

#endif
