#pragma once

#include <cassert>

class Matrix {
private:
	int m_matrix[5][5];
public:
	Matrix();

	int& operator()(int row, int column);
	const int& operator()(int row, int column) const;

	void operator()();
};

