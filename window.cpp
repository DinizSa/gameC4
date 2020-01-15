#include "window.h"
#include <iostream>
#include <SDL_image.h>
using namespace std;

Window::Window(const string& title, int width, int height) :
	_title(title), _width(width), _height(height)
{

	cout << "Window object constructed!" << endl;
	_closed = !init();
}
Window::~Window()
{
	cout << "Window object destructed!" << endl;
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	IMG_Quit();
	SDL_Quit();
}

bool Window::init() {
	if (SDL_Init(SDL_INIT_VIDEO != 0)) {
		cerr << "SDL failled to Initialize!" << endl;
		return 0;
	}

	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
		cout << "Error initializing IMG" << endl;
		return false;
	}

	_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, 0);
	if (_window == nullptr) {
		cout << "Not able to create Window" << endl;
		return 0;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (_renderer == nullptr) {
		cout << "Not able to create a Renderer!" << endl;
		return 0;
	}

	return true;
}

void Window::pollEvents(SDL_Event& event) {

	switch (event.type) {
	case SDL_QUIT:
		_closed = true;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_ESCAPE:
			_closed = true;
			break;
		default:
			break;
		}


	default:
		break;
	}
};

void Window::clear() const {
	SDL_RenderPresent(_renderer);
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);
}