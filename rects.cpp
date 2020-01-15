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
				_arrVecs.emplace_back(window, sizeBox, sizeBox, startX + sizeBox * x, startY + sizeBox * y, BOX_PATH);
			}
		}
	}
}