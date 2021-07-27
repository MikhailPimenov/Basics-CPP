#include "clone_array_and_double.cpp"

#include "DynamicArrayCopy.h"
#include "DynamicArrayMove.h"

template DynamicArrayCopy<int> clone_array_and_double(const DynamicArrayCopy<int>&);
template DynamicArrayMove<int> clone_array_and_double(const DynamicArrayMove<int>&);