#include <iostream>

#include "Dollars.h"

int main() {
	Dollars dollars1(7);
	Dollars dollars2(9);
	Dollars dollarsSum = dollars1 + dollars2;
	std::cout << "I have " << dollarsSum.getDollars() << " dollars." << std::endl;

	Dollars d1 = Dollars(5) + 5;
	Dollars d2 = 5 + Dollars(5);

	std::cout << "I have " << d1.getDollars() << " dollars." << std::endl;
	std::cout << "I have " << d2.getDollars() << " dollars." << std::endl;

	return 0;
}