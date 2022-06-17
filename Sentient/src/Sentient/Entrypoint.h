#pragma once
#include "Log.h"

#ifdef SNT_PLATFORM_WINDOWS

int main(int argc, char **argv)
{
	sentient::Log::Init();
	SNT_CORE_WARN("Initialized log!");
	SNT_INFO("Initilized log!");
	const auto app = sentient::CreateApplication();
	app->Run();
	delete app;
}

#else
#error Sentient only supports Windows.
#endif

