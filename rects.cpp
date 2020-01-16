#include <vector>
using namespace std; 
#include "window.h"
#include "rect.h"
#include "matrix.h"
#include "rects.h"
#include <iostream>

Rects::Rects(const int& nrElements, const int& nrElementsPerColumn) :
	_nrElements(nrElements), _nrElementsPerColumn(nrElementsPerColumn)
{
	_arrVecs.reserve(_nrElements);
}

void Rects::initRects(Window& window, Matrix& matrix) {
	for (int x = 0; x < _nrElements / _nrElementsPerColumn; x++)
	{
		for (int y = 0; y < _nrElementsPerColumn; y++)
		{
			if (matrix.getElement(x, y) > 0) {
				// With emplace_back() we create a Rect (with the respective parameters) inside the _arrVecs. 
				// With push_back() we would create a local copy of the object and then copy to the _arrVecs.
				_arrVecs.emplace_back(window, sizeBox, sizeBox, 2*startX - sizeBox * x, 2 * startY - sizeBox * y, BOX_PATH);
				//_arrVecs.emplace_back(window, sizeBox, sizeBox, startX + sizeBox * x, startY + sizeBox * y, BOX_PATH);
			}
		}
	}
}

// Poll events
void Rects::processEvent(SDL_Event& event) {
	for (unsigned int i = 0; i < _arrVecs.size(); i++) {
		_arrVecs[i].pollEventsRect(event);
	}
}

// State update
void Rects::stateUpdate(Matrix& matrix) {
	for (unsigned int i = 0; i < _arrVecs.size(); i++) {
		_arrVecs[i].fall();
	}
	int zero = 0;
	int one = 1;
	// We know that we move 1 in the array when we fin a box(x, y) positive
	int positionVec=0;
	for (int x = 0; x < _nrElements / _nrElementsPerColumn; x++)
	{
		for (int y = 0; y < _nrElementsPerColumn; y++)
		{
			int previousInd = y - one;
			// If box exists in this position
			if (matrix.getElement(x, y) > 0) {
				// If box not in the ground && has no box under
				cout << "Box. x:" << x << ", y:" << y << endl;
				if (y > 0) {
					cout << ". previuos:" << matrix.getElement(x, previousInd) ;
					if (y > 0 && matrix.getElement(x, previousInd) == 0) {
						matrix.setElement(x, y, zero);
						matrix.setElement(x, previousInd, one);
						_arrVecs[positionVec].setDistanceDown(sizeBox);
					}
				}
				cout << endl;
				positionVec++;
			}
		}
	}
}

// Render view
void Rects::renderRecs() {
	for (unsigned int i = 0;  i < _arrVecs.size(); i++) {
		_arrVecs[i].renderRect();
	}
}