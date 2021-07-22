#include "Dollars.h"

Dollars::Dollars() : m_dollars(0) {

}

Dollars::Dollars(int dollars) : m_dollars(dollars) {

}



Dollars Dollars::operator+(const Dollars& object) {
	return Dollars(this->m_dollars + object.m_dollars);
}

Dollars Dollars::operator+(int dollars) {
	return Dollars(this->m_dollars + dollars);
}

Dollars operator+(int dollars, const Dollars& object) {
	return Dollars(object.m_dollars + dollars);
}

int Dollars::getDollars() const {
	return this->m_dollars;
}