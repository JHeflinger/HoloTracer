#pragma once
#include "HoloLib/Core/Base.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace HoloLib {
	class HOLOLIB_API Log {
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define HL_CORE_ERROR(...)   ::HoloLib::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HL_CORE_WARN(...)    ::HoloLib::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HL_CORE_INFO(...)    ::HoloLib::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HL_CORE_TRACE(...)   ::HoloLib::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HL_CORE_FATAL(...)   ::HoloLib::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define HL_ERROR(...)        ::HoloLib::Log::GetClientLogger()->error(__VA_ARGS__)
#define HL_WARN(...)         ::HoloLib::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HL_INFO(...)         ::HoloLib::Log::GetClientLogger()->info(__VA_ARGS__)
#define HL_TRACE(...)        ::HoloLib::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HL_FATAL(...)        ::HoloLib::Log::GetClientLogger()->fatal(__VA_ARGS__)