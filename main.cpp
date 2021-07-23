#include <cassert>
#include <iostream>

#include "Fraction.h"
#include "SomeString.h"
#include "SomeStringExplicit.h"
#include "SomeStringDelete.h"

Fraction makeNegative(Fraction fraction) {
	fraction.setNumerator(-fraction.getNumerator());
	return fraction;
}

int main() {
	std::cout << makeNegative(7) << '\n';


	SomeString mystring = 'a'; 
	std::cout << mystring << '\n';


	// Error: constructor is explicit!
	 //SomeStringExplicit mystring2 = 'a';
	// std::cout << mystring2 << '\n';


	// Error: constructor(char) is deleted!
	 //SomeStringDelete mystring3 = 'a';
	 //std::cout << mystring3 << '\n';

	return 0;
}