#include "StaticArray.h"

template <typename T, int size>
T& StaticArray<T, size>::operator[](int index) {
	assert(index < size&& index >= 0 && "Error: index is out of range!");
	return m_data[index];
}

template <typename T, int size>
const T& StaticArray<T, size>::operator[](int index) const {
	assert(index < size&& index >= 0 && "Error: index is out of range!");
	return m_data[index];
}