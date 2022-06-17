#pragma once

#ifdef SNT_PLATFORM_WINDOWS
#ifdef SNT_BUILD_DLL
#define SENTIENT_API __declspec(dllexport)
#else
#define SENTIENT_API __declspec(dllimport)
#endif
#else
#error Sentient only supports Windows.
#endif

