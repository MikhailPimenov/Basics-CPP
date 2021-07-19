#include <iostream>
#include <string.h>

#include "StaticArray.h"
#include "print.h"

template <int size>
void print_main(const StaticArray<char, size>& object) {
	std::cout << "print_main(): char\n";
	for (int index = 0; index < size; ++index)
		std::cout << object[index];
	std::cout << '\n';
}

template <int size>
void print_main(const StaticArray<double, size>& object) {
	std::cout << "print_main(): double\n";
	for (int index = 0; index < size; ++index)
		std::cout << std::scientific << object[index] << ' ';
	std::cout << '\n';
}

template <typename T, int size>
void print_main(const StaticArray<T, size>& object) {
	std::cout << "print_main(): common\n";
	for (int index = 0; index < size; ++index)
		std::cout << object[index] << ' ';
	std::cout << '\n';
}

int main() {

	//StaticArray<int, 5> intArray;


	//for (int count = 0; count < 5; ++count)
	//	intArray[count] = count;
	//intArray.print();

	//print(intArray);
	//print_main(intArray);


	//StaticArray<double, 4> doubleArray;

	//for (int count = 0; count < 4; ++count)
	//	doubleArray[count] = (4. + 0.1 * count);
	//doubleArray.print();
	//print(doubleArray);
	//print_main(doubleArray);



	//StaticArray<char, 14> char14;
	//
	//strcpy_s(char14.data(), 14, "Hello, world!");


	//print(char14);
	//print_main(char14);


	//StaticArray<char, 12> char12;

	//strcpy_s(char12.data(), 12, "Hello, dad!");


	//print(char12);
	//print_main(char12);
}