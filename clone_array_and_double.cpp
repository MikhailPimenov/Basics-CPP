#include "clone_array_and_double.h"

template <template<typename> typename Array, typename Data>
Array<Data> clone_array_and_double(const Array<Data>& arr)
{
	Array<Data> dbl(arr.getLength());
	for (int i = 0; i < arr.getLength(); ++i)
		dbl[i] = arr[i] * 2;

	return dbl;
}
