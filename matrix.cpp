#include <iostream>
#include <array>
using namespace std;
#include "matrix.h"
#include "rect.h"


Matrix::Matrix(int nrElements, int nrElementsPerColumn):
	_nrElements(nrElements), _nrElementsPerColumn(nrElementsPerColumn)
{
	_VecMatrix.reserve(_nrElements);
}

void Matrix::initMatrix() {
	for (int i = 0; i < _nrElements / _nrElementsPerColumn; i++) {
		bool hasZero = false;
		for (int j = 0; j < _nrElementsPerColumn; j++) {
			int indice = i * _nrElementsPerColumn + j;
			if ((j == i) or (j == 0)) {
				_VecMatrix.push_back(1);
			}
			else {
				_VecMatrix.push_back(0);
			}
			//if (j == 0) { 
			//	// first in the collumn
			//	_VecMatrix.push_back(1);
			//}
			//else if (!hasZero) {
			//	// Random probability to have or not a box
			//	int random = rand() % 2;
			//	_VecMatrix.push_back(random);
			//	hasZero = (random == 0);
			//}
			//else {
			//	// Dont put boxes above an empty space
			//	_VecMatrix.push_back(0);
			//}
			////cout << "ind:" << indice << ", val:" << _VecMatrix[indice] << endl;
		}
	}
}

// Get value of element in the matrix
int Matrix::getElement(int &x, int &y) {
	return _VecMatrix[x * _nrElementsPerColumn + y];
}

// Set value of element in the matrix
void Matrix::setElement(int& x, int& y, int &val) {
	_VecMatrix[x * _nrElementsPerColumn + y] = val;
}