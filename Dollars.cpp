#include "Dollars.h"

Dollars::Dollars() : m_dollars(0) {

}

Dollars::Dollars(int dollars) : m_dollars(dollars) {

}

bool operator==(const Dollars &object1, const Dollars &object2) {
	return object1.m_dollars == object2.m_dollars;
}

bool operator!=(const Dollars &object1, const Dollars &object2) {
	return !(object1 == object2);
}

bool operator<(const Dollars &object1, const Dollars &object2) {
	return object1.m_dollars < object2.m_dollars;
}

bool operator>(const Dollars &object1, const Dollars &object2) {
	return object1.m_dollars > object2.m_dollars;
}

bool operator<=(const Dollars &object1, const Dollars &object2) {
	return object1.m_dollars <= object2.m_dollars;
}

bool operator>=(const Dollars &object1, const Dollars &object2) {
	return object1.m_dollars >= object2.m_dollars;
}