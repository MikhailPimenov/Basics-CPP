#include "DynamicArrayCopy.h"

template <typename T>
DynamicArrayCopy<T>::DynamicArrayCopy(int length) : DynamicArray_base<T>(length) {

}

template <typename T>
DynamicArrayCopy<T>::DynamicArrayCopy(const DynamicArrayCopy<T>& object) {
	this->m_length = object.m_length;
	if (!object.m_data) {
		this->m_data = nullptr;
		return;
	}

	this->m_data = new T[this->m_length];

	for (int index = 0; index < this->m_length; ++index)
		(this->m_data)[index] = (object.m_data)[index];
}

template <typename T>
DynamicArrayCopy<T>& DynamicArrayCopy<T>::operator=(const DynamicArrayCopy<T>& object) {
	if (this == &object)
		return *this;

	if (this->m_data)
		delete[] this->m_data;

	this->m_length = object.m_length;

	if (!object.m_data) {
		this->m_data = nullptr;
		return *this;
	}

	this->m_data = new T[this->m_length];

	for (int index = 0; index < this->m_length; ++index)
		(this->m_data)[index] = (object.m_data)[index];

	return *this;
}

