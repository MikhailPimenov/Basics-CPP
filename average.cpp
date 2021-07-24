#include "average.h"


template < typename T >
std::unique_ptr<T> average(const T* elements, int size) {
	std::unique_ptr<T> sum(std::make_unique<T>(T()));

	for (int index = 0; index < size; ++index)
		*(sum.get()) += elements[index];

	*(sum.get()) /= size;


	// "return sum;" gives the same result. 
	// Compiler understands that sum is local and is going to be destroyed,
	// so maybe compiler automatically converts sum to r-value
	return std::move(sum); 
}