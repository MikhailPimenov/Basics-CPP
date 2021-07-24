#pragma once

#include <iostream>

class Dollars final {
private:
	int m_dollars;

public:
	Dollars();
	Dollars(int dollars);

	friend void printDollars(const Dollars& object);
};

void printDollars(const Dollars& object);