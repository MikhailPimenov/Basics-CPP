#include "Cents.h"

Cents::Cents() : m_cents(0) {

}

Cents::Cents(int cents) : m_cents(cents) {

}

bool operator>=(const Cents& object1, const Cents& object2) {
	return object1.m_cents >= object2.m_cents;
}

Cents& Cents::operator+=(const Cents& object) {
	(this->m_cents) += object.m_cents;
	return *this;
}

Cents& Cents::operator/=(const Cents& object) {
	(this->m_cents) /= object.m_cents;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Cents& object) {
	out << object.m_cents << '\n';
	return out;
}


Cents::operator Dollars() const {
	return Dollars(m_cents / 100);
}

