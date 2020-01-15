#pragma once
#include <vector>

class Matrix {
private:
	int _nrElements;
	int _nrElementsPerColumn;
private:
	vector<int> _VecMatrix;
public:
	Matrix(int nrElements, int nrElementsPerColumn);
	void initMatrix();
	int getElement(int &x, int &y);
	void setElement(int& x, int& y, int& val);
};