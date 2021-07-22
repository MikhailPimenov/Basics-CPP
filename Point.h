#pragma once

#include <iostream>

class Point final{
private:
	double m_x;
	double m_y;
	double m_z;
public:
	Point();
	Point(double x, double y, double z);

	friend std::ostream& operator<<(std::ostream& out, const Point& object);
	friend std::istream& operator>>(std::istream& in, Point& object);
};

