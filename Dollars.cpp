#include "Dollars.h"

Dollars::Dollars() : m_dollars(0) {

}

Dollars::Dollars(int dollars) : m_dollars(dollars) {

}

Dollars& Dollars::operator+=(const Dollars& object) {
	(this->m_dollars) += object.m_dollars;
	return *this;
}

Dollars& Dollars::operator/=(const Dollars& object) {
	(this->m_dollars) /= object.m_dollars;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Dollars& object) {
	out << object.m_dollars << '\n';
	return out;
}


void printDollars(const Dollars &object) {
	std::cout << "Dollars(" << object.m_dollars << ")\n";
}