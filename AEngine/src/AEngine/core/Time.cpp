#include "aepch.h"
#include "Time.h"
#include <chrono>

static auto m_epoch = std::chrono::high_resolution_clock::now();

double AEngine::getTime() {

	return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - m_epoch)
		  .count() / 1000000000.0;
}
