#include <iostream>

#include "Matrix.h"
#include "Accumulator.h"

int main() {
	Matrix matrix;
	matrix(2, 3) = 3.6;
	std::cout << matrix(2, 3) << '\n';
	matrix(); // reset - it is not clear what is going on => bad practice
	std::cout << matrix(2, 3) << "\n\n";


	Accumulator accum;
	std::cout << accum(30) << '\n';  // 30
	std::cout << accum(40) << '\n';  // 70
	std::cout << accum() << '\n';    // 70
	std::cout << accum(100) << '\n'; // 170

	return 0;
}