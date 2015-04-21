/*!
	* \file main.cpp
	* \brief Program's entry point.
	* \author Jeremy ZYRA
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Window.hpp"
#include "Config.hpp"
#include "GameOfLife.hpp"
using namespace std;

/*!
	* \brief Function for print usage.
*/
void printUsage(char *name) {
	cout << "NAME" << endl;
	cout << "\tGameOfLife" << endl << endl;
	cout << "SYNOPSIS" << endl;
	cout << "\t" << name << " CONFIGURATION" << endl << endl; 
	cout << "DESCRIPTION" << endl;
	cout << "\tRun game of life viewer." << endl << endl;
	cout << "OPTIONS" << endl;
	cout << "\tPath to configuration file." << endl << endl;
	cout << "AUTHOR" << endl;
	cout << "\tJeremy ZYRA" << endl;
}

/*!
	* \brief Program's entry point.
*/
int main(int argc, char **argv) {
	//Check if there is one parameter.
	if (argc < 2) {
		printUsage(argv[0]);
	} else {
		string confFile = string(argv[1]);
		Config config(confFile);
		Window *window = new Window(config);
		window->run();
		delete(window);
	}
	return 0;
}
