#include "average.h"

template <typename T>
T average(const T* elements, int length) {
	T sum = 0;

	for (int i = 0; i < length; ++i)
		sum += elements[i];

	sum /= length;
	return sum;
}
