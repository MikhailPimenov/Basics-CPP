#pragma once

#include "Auto_ptr_base.h"

template <typename T>
class Auto_ptr: public Auto_ptr_base<T> {
public:
	Auto_ptr(T* data);
	//virtual ~Auto_ptr() override;
};

