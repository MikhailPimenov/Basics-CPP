#include "Dollars.h"

Dollars::Dollars(int dollars) : m_dollars(dollars) {
	
}

int Dollars::getDollars() const {
	return m_dollars;
}

Dollars operator+(const Dollars& object1, const Dollars& object2) {
	return Dollars(object1.getDollars() + object2.getDollars());
}

Dollars operator+(const Dollars& object, int dollars) {
	return Dollars(object.getDollars() + dollars);
}

Dollars operator+(int dollars, const Dollars& object) {
	return operator+(object, dollars);
}
