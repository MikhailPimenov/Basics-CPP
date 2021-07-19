#include "print.cpp"


template void print<int, 5>(const StaticArray<int, 5>&);
template void print<double, 4>(const StaticArray<double, 4>&);
template void print<char, 14>(const StaticArray<char, 14>&);
template void print<char, 12>(const StaticArray<char, 12>&);