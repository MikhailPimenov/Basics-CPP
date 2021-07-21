#include <iostream>

#include "Dollars.h"
#include "Values.h" 

int main() {
	Dollars dollars1(7);
	Dollars dollars2(9);
	Dollars dollarsSum = dollars1 + dollars2;
	std::cout << "I have " << dollarsSum.getDollars() << " dollars." << std::endl;

	Dollars d1 = Dollars(5) + 5;
	Dollars d2 = 5 + Dollars(5);

	std::cout << "I have " << d1.getDollars() << " dollars." << std::endl;
	std::cout << "I have " << d2.getDollars() << " dollars." << std::endl;

	Values v1(11, 14);
	Values v2(7, 10);
	Values v3(4, 13);

	Values vFinal = v1 + v2 + 6 + 9 + v3 + 17;

	std::cout << "Result: (" << vFinal.getMin() << ", " << vFinal.getMax() << ")\n";

	return 0;
}