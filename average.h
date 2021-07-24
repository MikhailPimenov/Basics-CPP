#pragma once

#include <memory>

template < typename T >
std::unique_ptr<T> average(const T* elements, int size);