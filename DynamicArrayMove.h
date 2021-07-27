#pragma once

#include "DynamicArray_base.h"

template <typename T>
class DynamicArrayMove : public DynamicArray_base<T> {
public:
	DynamicArrayMove(int length);
	DynamicArrayMove(DynamicArrayMove&& object) noexcept;
	DynamicArrayMove(const DynamicArrayMove&) = delete;

	DynamicArrayMove<T>& operator=(DynamicArrayMove&& object) noexcept;
	DynamicArrayMove<T>& operator=(const DynamicArrayMove&) = delete;
};

