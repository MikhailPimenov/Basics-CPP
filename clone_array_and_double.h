#pragma once

template <template<typename> typename Array, typename Data>
Array<Data> clone_array_and_double(const Array<Data>& arr);
