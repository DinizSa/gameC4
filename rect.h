#pragma once
#include "window.h"
class Rect : public Window {
public:
	Rect(const Window& window, int w, int h, int x, int y, int r, int g, int b, int a);
	Rect(const Window& window, int w, int h, int x, int y, const string & imagePath);
	~Rect();
	void renderRect() const;
	void pollEventsRect(SDL_Event& event);
	void checkClickInRect(int& eventX, int& eventY);
	void fall();
private:
	int _w, _h;
	int _x, _y;
	int _r, _g, _b, _a;
	SDL_Texture* _imageTexture = nullptr;
	int const SPEED = 10;
	int lastMouseX, lastMouseY = 0;
	bool isFalling = false;
}; 
