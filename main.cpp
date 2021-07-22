#include <iostream>

#include "Something.h"

int main() {
	Something something; // используем конструктор по умолчанию со значениями 0.0, 0.0, 0.0

	if (!something)
		std::cout << "Something is null.\n";
	else
		std::cout << "Something is not null.\n";

	Something something2(1.2, 2.1, 3.0);
	
	if (!something2)
		std::cout << "Something2 is null.\n";
	else
		std::cout << "Something2 is not null.\n";
	
	Something something3 = -something2;

	std::cout << something2 << '\n';
	std::cout << something3 << '\n';


	return 0;
}