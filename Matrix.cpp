#include "Matrix.h"

Matrix::Matrix() {
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			(this->m_matrix)[i][j] = 0;
}

int& Matrix::operator()(int row, int column) {
	assert(row >= 0 && row < 5 && "Error: row index is out of range.");
	assert(column >= 0 && column < 5 && "Error: column index is out of range.");

	return (this->m_matrix)[row][column];
}

const int& Matrix::operator()(int row, int column) const {
	assert(row >= 0 && row < 5 && "Error: row index is out of range.");
	assert(column >= 0 && column < 5 && "Error: column index is out of range.");

	return (this->m_matrix)[row][column];
}

void Matrix::operator()() {
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			(this->m_matrix)[i][j] = 0;
}