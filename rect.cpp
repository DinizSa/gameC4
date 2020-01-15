#include "rect.h"
#include "window.h"
#include <SDL_image.h>
using namespace std;
#include <iostream>

Rect::Rect(const Window& window, int w, int h, int x, int y, int r, int g, int b, int a) :
	Window(window), _w(w), _h(h), _x(x), _y(y), _r(r), _g(g), _b(b), _a(a)
{
	cout << "Rect rgb object constructed!" << endl;
}
Rect::Rect(const Window& window, int w, int h, int x, int y, const string &imagePath) :
	Window(window), _w(w), _h(h), _x(x), _y(y)
{
	SDL_Surface *surface = IMG_Load(imagePath.c_str());
	if (!surface) {
		cout << "Error initializing IMG" << endl;
	}
	else {
		_imageTexture = SDL_CreateTextureFromSurface(_renderer, surface);
		cout << "Rect image object constructed!" << endl;
		if (!_imageTexture) {
			cout << "Failed to create texture of image" << endl;
		}
	}
	SDL_FreeSurface(surface);

}

Rect::~Rect() {
	// TODO: ~Rect() está a destruir tambem a window
	SDL_DestroyTexture(_imageTexture);
	cout << "Rect object destructed!" << endl;
}

void Rect::renderRect() const {

	SDL_Rect rect = { _x, _y, _w, _h };
	if (_imageTexture) {
		SDL_RenderCopy(_renderer, _imageTexture, nullptr, &rect);
	}
	else {
		SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(_renderer, &rect);
	}
}

void Rect::pollEventsRect(SDL_Event& event) {
	switch (event.type)
	{
	case SDL_MOUSEMOTION:
		lastMouseX = event.motion.x;
		lastMouseY = event.motion.y;
		break;
	case  SDL_MOUSEBUTTONDOWN:
		checkClickInRect(lastMouseX, lastMouseY);

		break;
	default:
		break;
	}
}

void Rect::fall() {
	if (isFalling) {
		_y -= -1;
	}
}

// TODO: call this function only rect clicked
void Rect::checkClickInRect(int& eventX, int& eventY) {
	if (!isFalling && (eventX > _x) && (eventX - _x < _w) && (eventY > _y) && (eventY - _y < _h)) {
		isFalling = true;
	}
}

