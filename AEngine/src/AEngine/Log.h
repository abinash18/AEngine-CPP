/*****************************************************************/ /**
 * @file   Log.h
 * @brief	Wrapper class for spdlog
 *
 * @author abinash
 * @date   July 2021
 *********************************************************************/
#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace AEngine {
	class AE_API Log {
		public:
			/**
			 * .
			 *
			 */
			static void Init();

			/**
			 * .
			 *
			 * \return
			 */
			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

			/**
			 * .
			 *
			 * \return
			 */
			inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

		private:
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

/**
 * Core Engine Logging macros.
 */
#define AE_CORE_TRACE(...)    ::AEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AE_CORE_INFO(...)     ::AEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AE_CORE_WARN(...)     ::AEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AE_CORE_DEBUG(...)    ::AEngine::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define AE_CORE_ERROR(...)    ::AEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AE_CORE_CRITICAL(...) ::AEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

/**
 * User Extended Engine Logging macros.
 */
#define AE_TRACE(...)         ::AEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AE_INFO(...)          ::AEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define AE_WARN(...)          ::AEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AE_DEBUG(...)         ::AEngine::Log::GetClientLogger()->debug(__VA_ARGS__)
#define AE_ERROR(...)         ::AEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define AE_CRITICAL(...)      ::AEngine::Log::GetClientLogger()->critical(__VA_ARGS__)

/**
 * If this is a distrobution build then this will strip the logging statements from the binary saving memory.
 */
#ifdef AE_DISTROBUTION_BUILD
#define AE_CORE_TRACE(...)
#define AE_CORE_INFO(...)
#define AE_CORE_WARN(...)
#define AE_CORE_DEBUG(...)
#define AE_CORE_ERROR(...)
#define AE_CORE_CRITICAL(...)
#endif // AE_DISTROBUTION_BUILD
