#include <cassert>
#include <iostream>

#include "Cents.h"
#include "Dollars.h"

int main() {
	Cents cents(700);
	printDollars(cents); 

	cents = 780;
	printDollars(cents);

	cents = 1700;
	printDollars(cents);

	cents = 1580;
	printDollars(cents);
	return 0;
}
