/*****************************************************************/ /**
 * \file   Log.cpp
 * \brief	Class extending AEngine namespace for logging,
 *			containing s_CoreLogger and s_ClientLogger.
 *
 * \author abina
 * \date   July 2021
 *********************************************************************/
#include "aepch.h"
#include "Log.h"
#include <memory>
#include "spdlog/sinks/stdout_color_sinks.h"

namespace AEngine {
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	/**
	 *
	 * Initializer for spdlog.
	 */
	void Log::Init() {
		// Pattern to print logs.
		// [Time][T:Thread P:ProcessID][Loglevel] FileName:Line Source Function LoggerName: Log
		spdlog::set_pattern("%^[%T][T:%t P:%P][%l] %@ %! %n: %v%$");

		// Static logger object initialization

		// This logger is only used for the internal engine.
		s_CoreLogger = spdlog::stdout_color_mt("AEngine");
		s_CoreLogger->set_level(spdlog::level::level_enum::trace);

		// This logger is only used for the User Extended Engine.
		s_ClientLogger = spdlog::stdout_color_mt("UserExtendedEngine");
		s_ClientLogger->set_level(spdlog::level::level_enum::trace);
	}
}
