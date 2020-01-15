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

void pollEvents(Rect rects[2], Window& window);
void initArrayOfRects(Window& window, Matrix &matrix, vector<Rect> &arrVecs);

// Map generator
// Call array of Rec's

int main() {
	// Constants
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	const int NR_ELEMENTS = 20;
	const int NR_ELEMENTS_PER_COLUMN = 4;
	SDL_Event* event = nullptr;
	Matrix matrix(NR_ELEMENTS, NR_ELEMENTS_PER_COLUMN);
	vector<Rect> arrVecs;
	const string BOX_PATH = "assets/brownBox.png";
	Rects VecRects(NR_ELEMENTS, NR_ELEMENTS_PER_COLUMN);

	// State initialization
	Window window("Game", WINDOW_WIDTH, WINDOW_HEIGHT);
	matrix.initMatrix();
	VecRects.initRects(window, matrix);

	// Old way, to be replaced
	Rect rects[2] = {
		{window, 20, 20, 200, 200, BOX_PATH},
		{window, 20, 20, 300, 200, BOX_PATH}
	};

	while (!window.isClosed()) {
		// State update
		pollEvents(rects, window);
		for (int i = 0; i < 2; i++) {
			rects[i].fall();
		}
		// Render view (state -> view)
		for (int i = 0; i < 2; i++) { 
			rects[i].renderRect();
		}
		window.clear();
	}

	return 0;
}

// Listen to user events 
// Tutorial said it would be better to have this logic on a class, smany rect would get complicated
void pollEvents(Rect rects[2], Window& window) {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		for (int i = 0; i < 2; i++) {
			rects[i].pollEventsRect(event);
		}
		window.pollEvents(event);
	}
}

//// Initialize array: see where is one, and create array
//void initArrayOfRects(Window &window, Matrix &matrix, vector<Rect> &arrVecs) {
//	const string BOX_PATH = "assets/brownBox.png";
//	const int sizeBox = 20;
//	const int startX = 200;
//	const int startY = 200;
//	for (int x = 0; x < 5; x++)
//	{
//		for (int y = 0; y < 4; y++)
//		{
//			if (matrix.getElement(x, y)>0) {
//				arrVecs.push_back({ window, sizeBox, sizeBox, startX + sizeBox*x, startY + sizeBox * y, BOX_PATH });
//			}
//		}
//	}
//}
