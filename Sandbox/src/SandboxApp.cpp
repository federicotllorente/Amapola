#include <Amapola.h>
#include <imgui.h>

class ExampleLayer : public Amapola::Layer
{
public:
	ExampleLayer(
		float* bgColorRef,
		float* colorRef,
		glm::vec4& projectionPositionsRef,
		glm::vec3& viewCoordsRef,
		float* nearRef,
		float* farRef,
		float* angleXRef,
		float* angleZRef
	)
		: Layer("Example"),
		bgColorRef(bgColorRef),
		colorRef(colorRef),
		projectionPositionsRef(projectionPositionsRef),
		viewCoordsRef(viewCoordsRef),
		nearRef(nearRef),
		farRef(farRef),
		angleXRef(angleXRef),
		angleZRef(angleZRef)
	{
	}

	void OnUpdate() override
	{
		//AMPL_INFO("ExampleLayer::Update");
	}

	virtual void OnImGuiRender() override
	{
		// Set ImGui style for docking
		//ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());

		// Create the main docking window with title bar
		/*ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
		ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(viewport->Pos);
		ImGui::SetNextWindowSize(viewport->Size);
		ImGui::SetNextWindowViewport(viewport->ID);
		window_flags |= ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
		window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;*/

		// When using ImGuiDockNodeFlags_PassthruCentralNode, the dockspace will be drawn as a background
		/*if (ImGui::Begin("DockSpace Demo", nullptr, window_flags))
		{
			ImGui::DockSpace(ImGui::GetID("MyDockSpace"), ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_PassthruCentralNode);
		}
		ImGui::End();*/

		ImGui::Begin("Color settings");
		ImGui::ColorPicker3("Background color", bgColorRef);
		ImGui::ColorPicker3("Color", colorRef);
		ImGui::End();

		ImGui::Begin("Matrices settings");
		ImGui::SliderFloat4("Projection positions", &projectionPositionsRef.x, -5, 5);
		ImGui::SliderFloat3("View coords", &viewCoordsRef.x, -1, 1);
		ImGui::SliderFloat("Near", nearRef, -90.0f, 90.0f);
		ImGui::SliderFloat("Far", farRef, -90.0f, 90.0f);
		ImGui::SliderFloat("Rotation X", angleXRef, -90.0f, 90.0f);
		ImGui::SliderFloat("Rotation Z", angleZRef, -180.0f, 180.0f);
		ImGui::End();

		/*ImGui::Begin("Renderer");
		const std::string text = "Hello world " + "Fede";
		ImGui::Text((const char*)&text);
		ImGui::End();*/
	}

	void OnEvent(Amapola::Event& event) override
	{
		//AMPL_TRACE("[ExampleLayer::Event] {0}", event);
	}

	float* bgColorRef;
	float* colorRef;
	glm::vec4& projectionPositionsRef;
	glm::vec3& viewCoordsRef;
	float* nearRef;
	float* farRef;
	float* angleXRef;
	float* angleZRef;
};

class Sandbox : public Amapola::Application
{
public:
	Sandbox()
	{
		float* bgColorRef = &this->GetBgColor();
		float* colorRef = &this->GetColor();
		glm::vec4& projectionPositionsRef = this->GetProjectionPosition();
		glm::vec3& viewCoordsRef = this->GetViewCoords();
		float* nearRef = &this->GetNear();
		float* farRef = &this->GetFar();
		float* angleXRef = &this->GetAngleX();
		float* angleZRef = &this->GetAngleZ();
		PushLayer(new ExampleLayer(bgColorRef, colorRef, projectionPositionsRef, viewCoordsRef, nearRef, farRef, angleXRef, angleZRef));
	}

	~Sandbox()
	{
	}
};

Amapola::Application* Amapola::CreateApplication()
{
	return new Sandbox();
}
