#include "Point.h"

Point::Point() : m_x(0.0), m_y(0.0), m_z(0.0) {

}

Point::Point(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {

}

std::ostream& operator<<(std::ostream& out, const Point& object) {
	out << "Point(" << object.m_x << ", " << object.m_y << ", " << object.m_z << ')';
	return out;
}

std::istream& operator>>(std::istream& in, Point& object) {
	in >> object.m_x;
	in >> object.m_y;
	in >> object.m_z;

	return in;
}