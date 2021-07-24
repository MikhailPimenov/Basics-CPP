#pragma once

#include <iostream>

class Dollars final {
private:
	int m_dollars;

public:
	Dollars();
	Dollars(int dollars);

	Dollars& operator+=(const Dollars& object);
	Dollars& operator/=(const Dollars& object);

	friend std::ostream& operator<<(std::ostream& out, const Dollars& object);

	friend void printDollars(const Dollars& object);
};

void printDollars(const Dollars& object);