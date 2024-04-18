#pragma once

#ifdef AMPL_PLATFORM_WINDOWS

extern Amapola::Application* Amapola::CreateApplication();

int main(int argc, char** argv)
{
	Amapola::Log::Init();

	auto app = Amapola::CreateApplication();
	app->Run();
	delete app;
}

#endif
