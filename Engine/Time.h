#pragma once
#include <chrono>

class Time
{
private:
	std::chrono::steady_clock::time_point last;
public:
	Time();
	float getExecutionTime();
};