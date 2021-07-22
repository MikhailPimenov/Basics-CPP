#include <iostream>

#include "Array.h"

int main() {
	Array<int, 20> array;
	array[4] = 5; 
	std::cout << array[4] << '\n';

	return 0;
}