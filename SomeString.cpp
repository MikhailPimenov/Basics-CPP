#include "SomeString.h"

SomeString::SomeString(int size) {
	assert(size >= 0 && "Error: size can not be negative.");
	m_string.resize(size);
}

SomeString::SomeString(const char* cstring) : m_string(cstring) {

}

std::ostream& operator<<(std::ostream& out, const SomeString& object) {
	out << object.m_string;
	return out;
}