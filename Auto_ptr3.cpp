#include "Auto_ptr3.h"

template <typename T>
Auto_ptr3<T>::Auto_ptr3(T* data) : Auto_ptr_base<T>(data) {

}

template <typename T>
Auto_ptr3<T>::Auto_ptr3(const Auto_ptr3<T>& object) {
	if (!object.m_data) {
		this->m_data = nullptr;
		return;
	}

	this->m_data = new T;
	*(this->m_data) = *(object.m_data);
}

template <typename T>
Auto_ptr3<T>& Auto_ptr3<T>::operator=(const Auto_ptr3<T>& object) {
	if (this == &object)
		return *this;

	if (this->m_data)
		delete this->m_data;

	if (!object.m_data) {
		this->m_data = nullptr;
		return *this;
	}

	this->m_data = new T;
	*(this->m_data) = *(object.m_data);

	return *this;
}