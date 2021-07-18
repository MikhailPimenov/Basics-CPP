#include "Array.h"

template <typename T>
Array<T>::Array(): m_data(nullptr), m_length(0) {

}

template <typename T>
Array<T>::Array(int length) {
	assert(length >= 0 && "Error: length is negative!");
	m_data = new T[length];
	m_length = length;
}

template <typename T>
Array<T>::~Array() {
	delete[] m_data;
	m_length = 0;
}

template <typename T>
void Array<T>::erase() {
	delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}

template <typename T>
T& Array<T>::operator[](int index){
	assert(index >= 0 && index < m_length && "Error: index is out of range!");
	return m_data[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const {
	return operator[](index);
}

template <typename T>
int Array<T>::getLength() const {
	return m_length;
}

