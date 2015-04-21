#include "Window.hpp"

Window::Window(const Config &config) {
	_gameOfLife = new GameOfLife(config);
	_nbX = config.getXNb();
	_nbY = config.getYNb();
	_width = config.getWidth();
	_height = config.getHeight();
	if (SDL_Init(SDL_INIT_VIDEO) < 0)	 {
		cerr << "[-] SDL error : " << SDL_GetError() << endl;
		exit(1);
	}
	if ((_surface = SDL_SetVideoMode(_width, _height, BPP, SDL_SWSURFACE | SDL_HWSURFACE)) == NULL) {
		cerr << "[-] SDL error : " << SDL_GetError() << endl;
		exit(1);
	}
	SDL_WM_SetCaption(config.getTitle().c_str(), NULL);
}

Window::~Window() {
	delete (_gameOfLife);
}

void Window::draw() {
	Uint32 *pixels = (Uint32 *)_surface->pixels;
	int sizeX = _width / _nbX;
	int sizeY = _height / _nbY;
	bool **matrice = _gameOfLife->getMatrice();
	for (int i=0; i < _nbY; ++i) {
		for (int j=0; j < _nbX; ++j) {
			if(matrice[i][j]) {
				for(int x = j * sizeX; x < (j * sizeX)+sizeX; x++) {
					for(int y = i * sizeY; y < (i * sizeY)+sizeY; y++) {
						pixels[y*_width+x] = SDL_MapRGB(_surface->format, 0, 0, 0);
					}
				}
			} else {
				for(int x = j * sizeX; x < (j * sizeX)+sizeX; x++) {
					for(int y = i * sizeY; y < (i * sizeY)+sizeY; y++) {
						pixels[y*_width+x] = SDL_MapRGB(_surface->format, 255, 255, 255);
					}
				}
			}
		}
	}
	SDL_UpdateRect(_surface, 0, 0, _surface->w, _surface->h);
}

void Window::event() {
	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_ESCAPE:
						exit(0);
						break;
					case 'q':
						exit(0);
						break;
					default:
						break;
				}
				break;
			case SDL_QUIT:
				exit(0);
				break;
			default:
				break;
		}
	}
}

void Window::run() {
	for (;;) {
		event();
		draw();
		_gameOfLife->iterate();
	}
}
