#include <iostream>

#include "Fraction.h"

class DontCopyMe {
private:
	int m_value;

	DontCopyMe(const DontCopyMe &object) : m_value(object.m_value) {}
public:
	DontCopyMe(int value = 0) : m_value(value) {}

	friend std::ostream& operator<<(std::ostream& out, const DontCopyMe& object) {
		out << "DontCopyMe(" << object.m_value << ')';
		return out;
	}
};

int main() {
	std::cout << "Usual constructor:\n";
	Fraction f1(3, 4);
	std::cout << f1 << '\n';


	std::cout << "Copy constructor:\n";
	Fraction f2(f1);
	std::cout << f2 << '\n';

	std::cout << "Copy constructor will be ignored:\n";
	Fraction f3(Fraction(Fraction(7, 11)));
	std::cout << f3 << '\n';


	DontCopyMe dcm1(6);
	std::cout << dcm1 << '\n';

	// Error: copy constructor is private!
	// DontCopyMe dcm2(dcm1); // error!
	// std::cout << dcm2 << '\n';

	// Error: despite of ignoring copy constructor error will occure 
	// because copy constructor is private
	// DontCopyMe dcm3(DontCopyMe(DontCopyMe(77)));
	// std::cout << dcm3 << '\n';


	return 0;
}