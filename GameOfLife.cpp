#include "GameOfLife.hpp"

GameOfLife::GameOfLife(const Config &config) {
	cellular_t *cellulars = config.getCellulars();
	_height = config.getYNb();
	_width = config.getXNb();
	//Init matrice.
	_matrice = (bool **)malloc(_height*sizeof(bool *));
	for (int i=0; i < _height; ++i) {
		_matrice[i] = (bool *)malloc(_width*sizeof(bool));
	}
	for (int i=0; i < _height; ++i) {
		for (int j=0; j < _width; ++j) {
			_matrice[i][j] = true;
		}
	}
	//Init cellulars's positions.
	for (int i=0; i < config.getSize(); ++i) {
		_matrice[cellulars[i].y][cellulars[i].x] = cellulars[i].dead;	
	}
}

GameOfLife::~GameOfLife() {
	for (int i=0; i < _height; ++i) {
		free(_matrice[i]);
	}
	free(_matrice);
}

void GameOfLife::iterate() {
	bool **tmp = (bool **)malloc(_height*sizeof(bool *));
	//Init tmp matrice.
	for (int i=0; i < _height; ++i) {
		tmp[i] = (bool *)malloc(_width*sizeof(bool));
	}
	//Calculate next iteration of game of life.
	for (int i=0; i < _height; ++i) {
		for (int j=0; j < _width; ++j) {
			int alife = countAlife(j, i);
			if (_matrice[i][j]) {
				tmp[i][j] = (alife == 3) ? false : true;
			} else {
				tmp[i][j] = (alife == 3 || alife == 2) ? false : true;
			}
		}
	}
	//Copy tmp matrice.
	for (int i=0; i < _height; ++i) {
		for (int j=0; j < _width; ++j) {
			_matrice[i][j] = tmp[i][j];
		}
	}
	//Free tmp
	for (int i=0; i < _height; ++i) {
		free(tmp[i]);
	}
	free(tmp);
}

int GameOfLife::countAlife(int x, int y) {
	int cumul = 0;
	//Count alife cellulars in top line.
	if (!_matrice[(y-1 < 0) ? _height-1 : y-1][(x-1 < 0) ? _width-1 : x-1])
		++cumul;
	if (!_matrice[(y-1 < 0) ? _height-1 : y-1][x])
		++cumul;
	if (!_matrice[(y-1 < 0) ? _height-1 : y-1][(x+1 > _width-1) ? 0 : x+1])
		++cumul;
	//Count alife cellulars at left and right position of initial position.
	if (!_matrice[y][(x-1 < 0) ? _width-1 : x-1])
		++cumul;
	if (!_matrice[y][(x+1 > _width-1) ? 0 : x+1])
		++cumul;
	//Count alife cellulars in bottom line.
	if (!_matrice[(y+1 > _height-1) ? 0 : y+1][(x-1 < 0) ? _width-1 : x-1])
		++cumul;
	if (!_matrice[(y+1 > _height-1) ? 0 : y+1][x])
		++cumul;
	if (!_matrice[(y+1 > _height-1) ? 0 : y+1][(x+1 > _width-1) ? 0 : x+1])
		++cumul;
	return cumul;
}

bool **GameOfLife::getMatrice() const {
	return _matrice;
}
