#include "DynamicArray_base.h"

template <typename T>
DynamicArray_base<T>::DynamicArray_base(int length) : m_length(length) {
	assert(m_length >= 0 && "Error: length can not be negative.");
	
	m_data = new T[m_length];
}

template <typename T>
DynamicArray_base<T>::~DynamicArray_base() {
	delete[] m_data;
}

template <typename T>
int DynamicArray_base<T>::getLength() const {
	return m_length;
}

template <typename T>
T& DynamicArray_base<T>::operator[](int index) {
	assert(index >= 0 && index < m_length && "Error: index is out of range.");
	return m_data[index];
}

template <typename T>
const T& DynamicArray_base<T>::operator[](int index) const {
	assert(index >= 0 && index < m_length && "Error: index is out of range.");
	return m_data[index];
}