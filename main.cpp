#include <iostream>
#include <SDL.h>
#include <string>
using namespace std;
#include "window.h"
#include "matrix.h"
#include "rect.h"
#include "rects.h"
#include <vector>

#undef main

void pollEvents(Window& window, Rects& VecRects);


int main() {
	// Constants
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	const int NR_ELEMENTS = 20;
	const int NR_ELEMENTS_PER_COLUMN = 4;
	SDL_Event* event = nullptr;
	Matrix matrix(NR_ELEMENTS, NR_ELEMENTS_PER_COLUMN);
	//vector<Rect> arrVecs;
	const string BOX_PATH = "assets/brownBox.png";
	Rects VecRects(NR_ELEMENTS, NR_ELEMENTS_PER_COLUMN);

	// State initialization
	Window window("Game", WINDOW_WIDTH, WINDOW_HEIGHT);
	matrix.initMatrix();
	VecRects.initRects(window, matrix);


	while (!window.isClosed()) {
		//// State update
		pollEvents(window, VecRects);
		VecRects.stateUpdate(matrix);
		VecRects.renderRecs();
		window.clear();
	}

	return 0;
}

// Listen to user events (TODO: create a class for this)
void pollEvents(Window& window, Rects &VecRects) {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		VecRects.processEvent(event);
		window.pollEvents(event);
	}
}
