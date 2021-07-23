#include <iostream>

#include "Fraction.h"

Fraction makeNegative(Fraction object) {
	object.setNumerator(-object.getNumerator());

	return object;
}

Fraction boo() {
	Fraction result(3, 4);

	return result;
}

int main() {
	Fraction seven = Fraction(7);
	std::cout << seven << '\n';

	Fraction sixSeven(6, 7);
	std::cout << makeNegative(sixSeven) << '\n';

	Fraction threeFour = boo();

	return 0;
}