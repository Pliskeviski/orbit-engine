#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Orbit {
	class ORBIT_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()   { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core
#define ORBIT_CORE_WARN(...)  ::Orbit::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ORBIT_CORE_INFO(...)  ::Orbit::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ORBIT_CORE_ERROR(...) ::Orbit::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ORBIT_CORE_TRACE(...) ::Orbit::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ORBIT_CORE_FATAL(...) ::Orbit::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client
#define ORBIT_WARN(...)  ::Orbit::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ORBIT_INFO(...)  ::Orbit::Log::GetClientLogger()->info(__VA_ARGS__)
#define ORBIT_ERROR(...) ::Orbit::Log::GetClientLogger()->error(__VA_ARGS__)
#define ORBIT_TRACE(...) ::Orbit::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ORBIT_FATAL(...) ::Orbit::Log::GetClientLogger()->fatal(__VA_ARGS__)
