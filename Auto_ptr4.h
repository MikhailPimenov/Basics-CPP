#pragma once

#include "Auto_ptr_base.h"

template <typename T>
class Auto_ptr4 : public Auto_ptr_base<T> { 
	// better to make Auto_ptr4 being inherited from Auto_ptr3<T> to avoid 
	// duplicating copy constructor and copy '='
	// but from Auto_ptr_base<T> to gather here both move and copy semantics
public:
	Auto_ptr4(T* data = nullptr);
	Auto_ptr4(const Auto_ptr4<T>& object);
	Auto_ptr4(Auto_ptr4<T>&& object);

	Auto_ptr4<T>& operator=(const Auto_ptr4<T>& object);
	Auto_ptr4<T>& operator=(Auto_ptr4<T>&& object);
};

