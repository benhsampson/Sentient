#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace sentient
{
	class SENTIENT_API Log
	{
	public:
		static void Init();
		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_core_logger_; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_client_logger_; }
	private:
		static std::shared_ptr<spdlog::logger> s_core_logger_;
		static std::shared_ptr<spdlog::logger> s_client_logger_;
	};

}

#define SNT_CORE_FATAL(...) ::sentient::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define SNT_CORE_ERROR(...) ::sentient::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SNT_CORE_WARN(...) ::sentient::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SNT_CORE_INFO(...) ::sentient::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SNT_CORE_TRACE(...) ::sentient::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define SNT_FATAL(...) ::sentient::Log::GetClientLogger()->critical(__VA_ARGS__)
#define SNT_ERROR(...) ::sentient::Log::GetClientLogger()->error(__VA_ARGS__)
#define SNT_WARN(...) ::sentient::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SNT_INFO(...) ::sentient::Log::GetClientLogger()->info(__VA_ARGS__)
#define SNT_TRACE(...) ::sentient::Log::GetClientLogger()->trace(__VA_ARGS__)