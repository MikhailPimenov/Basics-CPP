#include "average.cpp"

#include "Cents.h"
#include "Dollars.h"

template std::unique_ptr<Cents> average(const Cents*, int);
template std::unique_ptr<Dollars> average(const Dollars*, int);