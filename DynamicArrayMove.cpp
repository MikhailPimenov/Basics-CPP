#include "DynamicArrayMove.h"

template <typename T>
DynamicArrayMove<T>::DynamicArrayMove(int length) : DynamicArray_base<T>(length) {

}

template <typename T>
DynamicArrayMove<T>::DynamicArrayMove(DynamicArrayMove<T>&& object) noexcept {
	this->m_length = object.m_length;
	this->m_data = object.m_data;
	
	object.m_data = nullptr;
}

template <typename T>
DynamicArrayMove<T>& DynamicArrayMove<T>::operator=(DynamicArrayMove<T>&& object) noexcept {
	if (this == &object)
		return *this;

	if (this->m_data)
		delete[] this->m_data;

	this->m_length = object.m_length;
	this->m_data = object.m_data;

	object.m_data = nullptr;
	return *this;
}