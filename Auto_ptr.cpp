#include "Auto_ptr.h"

template <typename T>
Auto_ptr<T>::Auto_ptr(T* data) : Auto_ptr_base<T>(data) {

}

//template <typename T>
//Auto_ptr<T>::~Auto_ptr() {
//
//}