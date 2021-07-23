#include "SomeStringDelete.h"

SomeStringDelete::SomeStringDelete(int size) {
	assert(size >= 0 && "Error: size can not be negative.");
	m_string.resize(size);
}

SomeStringDelete::SomeStringDelete(const char* cstring) : m_string(cstring) {

}

std::ostream& operator<<(std::ostream& out, const SomeStringDelete& object) {
	out << object.m_string;
	return out;
}
