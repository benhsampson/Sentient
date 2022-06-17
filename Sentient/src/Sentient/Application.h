#pragma once

#include "Core.h"

namespace sentient
{
	class SENTIENT_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();
}

