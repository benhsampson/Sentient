#include <Sentient.h>

class Sandbox : public sentient::Application
{
public:
	Sandbox() = default;

	~Sandbox() override = default;
};

sentient::Application* sentient::CreateApplication()
{
	return new Sandbox();
}
