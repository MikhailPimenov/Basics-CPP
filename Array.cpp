#include "Array.h"

template <typename T, int size>
Array<T, size>::Array() {

}

template <typename T, int size>
T& Array<T, size>::operator[](int index) {
	assert(index >= 0 && index < size && "Error: index is out of range.");
	return (this->m_data)[index];
}

template <typename T, int size>
const T& Array<T, size>::operator[](int index) const {
	assert(index >= 0 && index < size && "Error: index is out of range.");
	return (this->m_data)[index];
}