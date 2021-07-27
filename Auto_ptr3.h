#pragma once

#include "Auto_ptr_base.h"


template <typename T>
class Auto_ptr3 : public Auto_ptr_base <T> {
public:
	Auto_ptr3(T* data = nullptr);
	Auto_ptr3(const Auto_ptr3<T>& object);

	Auto_ptr3<T>& operator=(const Auto_ptr3<T>& object);
};

