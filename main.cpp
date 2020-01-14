#include <iostream>
#include <SDL.h>
#include <string>
using namespace std;
#include "window.h"
#include "rect.h"

void pollEvents(Rect& rect, Rect& rect2, Window& window);

#undef main
// Map generator
// Call array of Rec's

int main() {
	SDL_Event* event = nullptr;
	Window window("Game", 800, 600);
	// Rect rect1(window, 20, 20, 200, 200, 200, 0, 200, 255);
	// Rect rect2(window, 20, 20, 400, 250, 200, 0, 200, 255);
	Rect rect1(window, 20, 20, 200, 200, "assets/brownBox.png");
	Rect rect2(window, 20, 20, 300, 600, "assets/brownBox.png");


	while (!window.isClosed()) {
		pollEvents(rect1, rect2, window);
		rect1.fall();
		rect2.fall();
		rect1.renderRect();
		rect2.renderRect();
		window.clear();
	}

	return 0;
}

// Listen to user events and call the classes methods to handle them
// Tutorial said it would be better to have this logic on a class, smany rect would get complicated
void pollEvents(Rect& rect1, Rect& rect2, Window& window) {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		rect1.pollEventsRect(event);
		rect2.pollEventsRect(event);
		window.pollEvents(event);
	}
}