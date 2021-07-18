#include <iostream>

#include "Dollars.h"
#include "average.h"
#include "maximum.h"


int main() {
	Dollars dollars[] = { Dollars(7), Dollars(8), Dollars(9), Dollars(10), Dollars(11) };
	const int length = sizeof(dollars) / sizeof(dollars[0]);

	std::cout << "average = " << average(dollars, length) << '\n';

	std::cout << "maximum = " << maximum(Dollars(35), Dollars(77)) << '\n';

	return 0;
}