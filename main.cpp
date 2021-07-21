#include <iostream>

#include "Dollars.h"



int main() {
	Dollars dollars1(7);
	Dollars dollars2(9);
	Dollars dollarsSum = dollars1 + dollars2; 
	std::cout << "I have " << dollarsSum.getDollars() << " dollars." << std::endl;

	return 0;
}