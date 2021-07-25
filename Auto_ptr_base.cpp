#include "Auto_ptr_base.h"

template <typename T>
Auto_ptr_base<T>::Auto_ptr_base(T* data) : m_data(data) {

}

template <typename T>
Auto_ptr_base<T>::~Auto_ptr_base() {

	delete m_data;
}

template <typename T>
T& Auto_ptr_base<T>::operator*() {
	return *m_data;
}

template <typename T>
const T& Auto_ptr_base<T>::operator*() const {
	return *m_data;
}

template <typename T>
T* Auto_ptr_base<T>::operator->() {
	return m_data;
}

template <typename T>
const T* Auto_ptr_base<T>::operator->() const {
	return m_data;
}

template <typename T>
bool Auto_ptr_base<T>::isNull() const {
	return m_data == nullptr;
}