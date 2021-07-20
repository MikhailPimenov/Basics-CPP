#include "print.h"

template <typename T, int size>
void print(const StaticArray<T, size>& object) {
	std::cout << "print(): common\n";
	for (int index = 0; index < size; ++index)
		std::cout << object[index] << ' ';
	std::cout << '\n';
}

template <int size>
void print(const StaticArray<char, size>& object) {
	std::cout << "print(): char\n";
	for (int index = 0; index < size; ++index)
		std::cout << object[index];
	std::cout << '\n';
}

template <int size>
void print(const StaticArray<double, size>& object) {
	std::cout << "print(): double\n";
	for (int index = 0; index < size; ++index)
		std::cout << std::scientific << object[index] << ' ';
	std::cout << std::defaultfloat << '\n';
}



