#include <cassert>
#include <iostream>

#include "Fraction.h"
#include "SomeString.h"
#include "SomeStringShallowCopying.h"

int main() {
	Fraction f1(7, 9);
	Fraction f2(8, 11);

	f2 = f1;
	std::cout << f2 << '\n';
	f2 = f2;
	std::cout << f2 << '\n';

	SomeStringShallowCopying mike("Mike");
	{
		SomeStringShallowCopying jobless = mike;
		std::cout << jobless << '\n';
	}
	std::cout << mike << '\n'; // undefined behaviour - trying to access deleted memory


	SomeString anton("Anton");
	{
		SomeString employee = anton;
		std::cout << employee << '\n';
	}
	std::cout << anton << '\n';


	return 0;
} // undefined behaviour - trying to delete deleted memory again