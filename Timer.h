#pragma once

#include <chrono>

class Timer {
	using clock_t = std::chrono::high_resolution_clock;
	using seconds_t = std::chrono::duration<double, std::ratio<1>>;

private:
	std::chrono::time_point<clock_t> m_begin;

public:
	Timer();

	void reset();

	double elapsed() const;
};

