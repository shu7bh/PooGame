#include "Time.h"

Time::Time()
	: last(std::chrono::steady_clock::now()) {}

float Time::getExecutionTime()
{
	const decltype(last) now = std::chrono::steady_clock::now();
	std::chrono::duration<float> duration = now - last;
	last = now;
	return duration.count();
}
