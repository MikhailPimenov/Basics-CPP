#include <iostream>

#include "StaticArray.h"

int main() {
    StaticArray<int, 10> intArray;


    for (int count = 0; count < 10; ++count)
        intArray[count] = count;


    for (int count = 9; count >= 0; --count)
        std::cout << intArray[count] << " ";
    std::cout << '\n';


    StaticArray<double, 5> doubleArray;


    for (int count = 0; count < 5; ++count)
        doubleArray[count] = 5.5 + 0.1 * count;


    for (int count = 0; count < 5; ++count)
        std::cout << doubleArray[count] << ' ';

    return 0;
}