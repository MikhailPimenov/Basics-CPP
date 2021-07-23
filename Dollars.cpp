#include "Dollars.h"

Dollars::Dollars() : m_dollars(0) {

}

Dollars::Dollars(int dollars) : m_dollars(dollars) {

}

void printDollars(const Dollars &object) {
	std::cout << "Dollars(" << object.m_dollars << ")\n";
}