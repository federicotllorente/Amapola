#include <Amapola.h>

class Sandbox : public Amapola::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

Amapola::Application* Amapola::CreateApplication()
{
	return new Sandbox();
}
