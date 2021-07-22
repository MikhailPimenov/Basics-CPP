#include "Something.h"

Something::Something() : m_x(0.0), m_y(0.0), m_z(0.0) {
}

Something::Something(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {
}

Something Something::operator-() const {
	return Something(-m_x, -m_y, -m_z);
}

bool Something::operator!() const {
	static const double epsilon = 1e-12;

	return (std::abs(m_x) < epsilon) && (std::abs(m_y) < epsilon) && (std::abs(m_z) < epsilon);
}

std::ostream& operator<<(std::ostream& out, const Something& object) {
	out << "Something(" << object.m_x << ", " << object.m_y << ", " << object.m_z << ')';
	return out;
}

std::istream& operator>>(std::istream& in, Something& object) {
	in >> object.m_x;
	in >> object.m_y;
	in >> object.m_z;

	return in;
}