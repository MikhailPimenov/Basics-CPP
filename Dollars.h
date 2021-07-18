#pragma once

#include <iostream>

class Dollars final
{
private:
	int m_dollars;

public:
	Dollars(int dollars = 0);

	Dollars& operator+=(const Dollars& object);
	Dollars& operator/=(const Dollars& object);
	bool operator>=(const Dollars& object) const;

	friend std::ostream& operator<<(std::ostream& out, const Dollars& object);
};

