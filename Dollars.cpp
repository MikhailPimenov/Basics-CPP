#include "Dollars.h"


Dollars::Dollars(int dollars) : m_dollars(dollars) {

}

Dollars& Dollars::operator+=(const Dollars& object) {
	this->m_dollars += object.m_dollars;
	return *this;
}

Dollars& Dollars::operator/=(const Dollars& object) {
	this->m_dollars /= object.m_dollars;
	return *this;
}

bool Dollars::operator>=(const Dollars& object) const {
	return this->m_dollars >= object.m_dollars;
}

std::ostream& operator<<(std::ostream& out, const Dollars& object) {
	out << object.m_dollars;
	return out;
}