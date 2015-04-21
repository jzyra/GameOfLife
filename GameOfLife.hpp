/*!
	* \file GameOfLife.hpp
	* \brief Class for represent game of life.
	* \author Jeremy ZYRA
	* \version 1.0
*/
#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <iostream>
#include "Config.hpp"
using namespace std;

class GameOfLife {

	public:
	/*!
		* \brief GameOfLife Constructor.
		Config class's constructor.
		* \param configuration object.
	*/
	GameOfLife(const Config &config);
	/*!
		* \brief GameOfLife Destructor.
		Config class's destructor.
	*/
	~GameOfLife();
	/*!
		* \brief Update next cellulars's positions.
	*/
	void iterate();
	/*!
		* \brief Accessor on cellulars's matrice.
		* \return Stat matrice.
	*/
	bool **getMatrice() const;

	private:
	bool **_matrice;
	int _height;
	int _width;
	/*!
		* \brief Count alife cellulars around cellular.
		* \param cellular'position in x axis.
		* \param cellular'position in y axis.
	*/
	int countAlife(int x, int y);

};

#endif
