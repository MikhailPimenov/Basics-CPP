#include "Auto_ptr4.h"

template <typename T>
Auto_ptr4<T>::Auto_ptr4(T* data) : Auto_ptr_base<T>(data) {

}

template <typename T>
Auto_ptr4<T>::Auto_ptr4(const Auto_ptr4<T>& object) {
	if (!object.m_data) {
		this->m_data = nullptr;
		return;
	}

	this->m_data = new T;
	*(this->m_data) = *(object.m_data);
}

template <typename T>
Auto_ptr4<T>::Auto_ptr4(Auto_ptr4<T>&& object) {
	this->m_data = object.m_data;
	object.m_data = nullptr;
}

template <typename T>
Auto_ptr4<T>& Auto_ptr4<T>::operator=(const Auto_ptr4<T>& object) {
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

template <typename T>
Auto_ptr4<T>& Auto_ptr4<T>::operator=(Auto_ptr4<T>&& object) {
	if (this == &object)
		return *this;

	if (this->m_data)
		delete this->m_data;

	this->m_data = object.m_data;
	object.m_data = nullptr;

	return *this;
}