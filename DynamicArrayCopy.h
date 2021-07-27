#pragma once
#include "DynamicArray_base.h"

template <typename T>
class DynamicArrayCopy : public DynamicArray_base <T> {
public:
	DynamicArrayCopy(int length);
	DynamicArrayCopy(const DynamicArrayCopy& object);
	DynamicArrayCopy(DynamicArrayCopy&&) = delete;

	DynamicArrayCopy<T>& operator=(const DynamicArrayCopy& object);
	DynamicArrayCopy<T>& operator=(DynamicArrayCopy&&) = delete;
};

