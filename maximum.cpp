#include "maximum.h"

template <typename T>
const T& maximum(const T& a, const T& b) {
	return (a >= b) ? a : b;
}