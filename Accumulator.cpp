#include "Accumulator.h"

Accumulator::Accumulator() : m_number(0) {

}

const int& Accumulator::operator()(int increment) {
	return ((this->m_number) += increment);
}