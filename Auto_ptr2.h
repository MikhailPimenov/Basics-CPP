#pragma once

#include "Auto_ptr_base.h"

template <typename T>
class Auto_ptr2 : public Auto_ptr_base <T> {
public:
	Auto_ptr2(T* data = nullptr);

	Auto_ptr2(Auto_ptr2<T>& ojbect);

	Auto_ptr2<T>& operator=(Auto_ptr2<T>& object);
};