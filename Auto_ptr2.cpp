#include "Auto_ptr2.h"

template <typename T>
Auto_ptr2<T>::Auto_ptr2(T* data) : Auto_ptr_base<T>(data) {

}

template <typename T>
Auto_ptr2<T>::Auto_ptr2(Auto_ptr2<T>& object) {
	if (this->m_data)
		delete this->m_data;

	this->m_data = object.m_data;
	object.m_data = nullptr;
}

template <typename T>
Auto_ptr2<T>& Auto_ptr2<T>::operator=(Auto_ptr2<T>& object) {
	if (this == &object)
		return *this;

	if (this->m_data)
		delete this->m_data;

	this->m_data = object.m_data;
	object.m_data = nullptr;

	return *this;
}