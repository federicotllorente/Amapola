#include <Amapola.h>

class ExampleLayer : public Amapola::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//AMPL_INFO("ExampleLayer::Update");
	}

	void OnEvent(Amapola::Event& event) override
	{
		AMPL_TRACE("[ExampleLayer::Event] {0}", event);
	}
};

class Sandbox : public Amapola::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Amapola::ImGuiLayer());
	}

	~Sandbox()
	{
	}
};

Amapola::Application* Amapola::CreateApplication()
{
	return new Sandbox();
}
