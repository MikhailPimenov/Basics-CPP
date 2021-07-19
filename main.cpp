#include <iostream>

#include "Repository8.h"

int main() {
    
    Repository8<int> intRepository;

    for (int count = 0; count < 8; ++count)
        intRepository.set(count, count);

    for (int count = 0; count < 8; ++count)
        std::cout << intRepository.get(count) << '\n';

    
    Repository8<bool> boolRepository;

    for (int count = 0; count < 8; ++count)
        boolRepository.set(count, count % 5);

    for (int count = 0; count < 8; ++count)
        std::cout << (boolRepository.get(count) ? "true" : "false") << '\n';

    return 0;
}