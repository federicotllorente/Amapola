#include <Amapola.h>
#include <imgui.h>

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

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("ImGui Test");
		ImGui::Text("Hello world");
		ImGui::End();

		ImGui::Begin("ImGui Test 2");
		ImGui::Text("Hello world 2");
		ImGui::End();

		ImGui::Begin("ImGui Test 3");
		ImGui::Text("Hello world 3");
		ImGui::End();
	}

	void OnEvent(Amapola::Event& event) override
	{
		//AMPL_TRACE("[ExampleLayer::Event] {0}", event);
	}
};

class Sandbox : public Amapola::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{
	}
};

Amapola::Application* Amapola::CreateApplication()
{
	return new Sandbox();
}
