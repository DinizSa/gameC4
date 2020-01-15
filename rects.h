#include <vector>
using namespace std;
#include "window.h"
#include "rect.h"
#include "matrix.h"

#pragma once
class Rects {
public:
	Rects(const int &nrElements, const int &nrElementsPerColumn);
	void initRects(Window &window, Matrix &matrix);
private:
	const string BOX_PATH = "assets/brownBox.png";
	const int sizeBox = 20;
	const int startX = 200;
	const int startY = 200;
	int _nrElements;
	int _nrElementsPerColumn;
	vector<Rect> _arrVecs;
};