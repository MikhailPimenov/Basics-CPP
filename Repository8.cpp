#include "Repository8.h"

template <typename T>
Repository8<T>::Repository8<T>() {
	std::cout << "Repository8(): common repository8\n";
}

template <typename T>
void Repository8<T>::set(int index, T value) {
	assert(index >= 0 && index < 8 && "Error: index is out of range!");
	m_data[index] = value;
}

template <typename T>
const T& Repository8<T>::get(int index) const {
	assert(index >= 0 && index < 8 && "Error: index is out of range!");
	return m_data[index];
}




