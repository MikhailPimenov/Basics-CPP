#include <iostream>

#include "Number.h"

int main() {
    int value = 6;
    Number number(value);

    std::cout << "1) " << value <<": " << number << '\n';
    std::cout << "2) " << ++value << ": " << ++number << '\n';   // calling Number::operator++();
    std::cout << "3) " << value++ << ": " << number++ << '\n';       // calling Number::operator++(int);
    std::cout << "4) " << value << ": " << number << '\n';
    std::cout << "5) " << --value << ": " << --number << '\n';   // calling Number::operator--();
    std::cout << "6) " << value-- << ": " << number-- << '\n';       // calling Number::operator--(int);
    std::cout << "7) " << value << ": " << number << '\n';

	return 0;
}