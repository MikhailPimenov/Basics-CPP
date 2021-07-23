#include "SomeStringExplicit.h"


explicit SomeStringExplicit::SomeStringExplicit(int size) {
	assert(size >= 0 && "Error: size can not be negative.");
	m_string.resize(size);
}
SomeStringExplicit::SomeStringExplicit(const char* cstring) : m_string(cstring) {}

std::ostream& operator<<(std::ostream& out, const SomeStringExplicit& object) {
	out << object.m_string;
	return out;
}
