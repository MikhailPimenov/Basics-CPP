#pragma once
#include "DynamicArray_base.h"

template <typename T>
class DynamicArrayCopy : public DynamicArray_base <T> {
public:
	DynamicArrayCopy(int length);
	DynamicArrayCopy(const DynamicArrayCopy& object);

	// DynamicArrayCopy(DynamicArrayCopy&&) is used for return statement 
	// because after returning local object by value local object is copied 
	// to temporary object (using DynamicArrayCopy(const DynamicArrayCopy&)), 
	// then local object is destroyed, then recieving object is being created
	// from temporary object using exactly DynamicArrayCopy(DynamicArrayCopy&&), 
	// so never delete DynamicArrayCopy(DynamicArrayCopy&&).
	// Default DynamicArrayCopy(DynamicArrayCopy&&) does not provide move semantics
	//DynamicArrayCopy(DynamicArrayCopy&&) = delete; // constructor(Type&& object) is used for tempo

	DynamicArrayCopy<T>& operator=(const DynamicArrayCopy& object);
	
	// Same here, but instead of constructing new recieving object
	// operator=(DynamicArrayCopy&&) is used for assignment temporary object
	// from return-statement to existing object,
	// so never delete operator=(DynamicArrayCopy&&).
	// Default operator=(DynamicArrayCopy&&) does not provide move semantics
	//DynamicArrayCopy<T>& operator=(DynamicArrayCopy&&) = delete;
};

