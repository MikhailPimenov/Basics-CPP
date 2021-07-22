#pragma once

#include <iostream>
#include <cmath>

class Something final {
private:
	double m_x;
	double m_y;
	double m_z;

public:
	Something();
	Something(double x, double y, double z);

	Something operator-() const;
	bool operator!() const;

	friend std::ostream& operator<<(std::ostream& out, const Something& obejct);
	friend std::istream& operator>>(std::istream& in, Something& object);
};

