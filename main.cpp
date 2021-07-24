#include <cassert>
#include <iostream>

#include "Fraction.h"
#include "SomeString.h"


int main() {

	Fraction f1(7, 9);
	Fraction f2(8, 11);

	f2 = f1;
	std::cout << f2 << '\n';
	f2 = f2;
	std::cout << f2 << '\n';



	SomeString anton("Anton");
	SomeString employee;
	employee = anton;
	std::cout << employee << '\n';

	anton = anton;
	std::cout << anton << '\n';

	return 0;
}