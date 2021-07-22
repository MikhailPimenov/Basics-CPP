#include <iostream>

#include "Dollars.h"

int main() {
    Dollars ten(10);
    Dollars sameten(10);
    Dollars seven(7);

    if (ten > seven)
        std::cout << "Ten dollars are greater than seven dollars.\n";
    if (ten >= seven)
        std::cout << "Ten dollars are greater than or equal to seven dollars.\n";
    if (ten < seven)
        std::cout << "Seven dollars are greater than ten dollars.\n";
    if (ten <= seven)
        std::cout << "Seven dollars are greater than or equal to ten dollars.\n";
    if (ten == sameten)
        std::cout << "Ten dollars are equal to ten dollars.\n";
    if (ten != seven)
        std::cout << "Ten dollars are not equal to seven dollars.\n";


	return 0;
}