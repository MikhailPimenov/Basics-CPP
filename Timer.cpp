#include "Timer.h"

Timer::Timer() : m_begin(clock_t::now()) {

}

void Timer::reset() {
	m_begin = clock_t::now();
}

double Timer::elapsed() const {
	return (std::chrono::duration_cast<seconds_t>(clock_t::now() - m_begin)).count();
}