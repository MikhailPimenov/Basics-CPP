#include <cassert>
#include <iostream>

#include "Cents.h"
#include "Dollars.h"

#include "maximum.h"
#include "average.h"




int main() {

	Cents nickle{ 5 };
	Cents dime{ 10 };

	Cents bigger = maximum(nickle, dime);
	std::cout << bigger << '\n';

	
	Cents centsArray[] = { Cents(5), Cents(10), Cents(15), Cents(14) };
	Dollars dollarsArray[] = { Dollars(20), Dollars(30), Dollars(40), Dollars(50), Dollars(60) };
	
	std::cout << *(average(centsArray, 4).get()) << '\n';
	std::cout << *(average(dollarsArray, 5).get()) << '\n';
	
	return 0;
}
