#pragma once

#ifdef SNT_PLATFORM_WINDOWS

extern sentient::Application* sentient::CreateApplication();

int main(int argc, char **argv)
{
	const auto app = sentient::CreateApplication();
	app->Run();
	delete app;
}

#else
#error Sentient only supports Windows.
#endif

