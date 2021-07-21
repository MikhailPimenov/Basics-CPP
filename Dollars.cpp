#include "Dollars.h"

Dollars::Dollars(int dollars) : m_dollars(dollars) {
	std::cout << "Dollars acquired\n";
}

Dollars::Dollars(const Dollars& object) : m_dollars(object.m_dollars) {
	std::cout << "Dollars acquired: copy constructor\n";
}

Dollars::Dollars(Dollars&& object) : m_dollars(object.m_dollars) {
	std::cout << "Dollars acquired: move constructor\n";
}

Dollars& Dollars::operator=(const Dollars& object) {
	std::cout << "copy assignment operator()\n";
	
	if (this == &object)
		return *this;

	m_dollars = object.m_dollars;
	return *this;
}

Dollars& Dollars::operator=(Dollars&& object) noexcept{
	std::cout << "move assignment operator()\n";
	if (this == &object)
		return *this;

	m_dollars = object.m_dollars;
	return *this;
}



int Dollars::getDollars() const {
	return m_dollars;
}

Dollars operator+(const Dollars& object1, const Dollars& object2) {
	return Dollars(object1.m_dollars + object2.m_dollars);
}

Dollars operator+(const Dollars& object, int dollars) {
	return Dollars(object.m_dollars + dollars);
}

Dollars operator+(int dollars, const Dollars& object) {
	return operator+(object, dollars);
}
