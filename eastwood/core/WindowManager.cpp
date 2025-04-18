#include "WindowManager.h"

#include "Eastwood.h"

namespace eastwood
{
	WindowManager* WindowManager::Get()
	{
		return Eastwood::Instance()->GetWindowManager();
	}

	Window* WindowManager::CreateWindow()
	{
		Window* window = new Window(this);
		
		if (!window->Initialize())
		{
			window->Destroy();
			return nullptr;
		}

		mWindows.push_back(window);
		return window;
	}

	const std::vector<Window*>& WindowManager::GetWindows() const
	{
		return mWindows;
	}

	void WindowManager::Update()
	{
		glfwPollEvents();
	}

	WindowManager::WindowManager()
	{
		
	}

	WindowManager::~WindowManager()
	{

	}

	bool WindowManager::Initialize()
	{
		glfwInit();
	}

	bool WindowManager::Destroy()
	{
		assert(mWindows.empty());

		if (!mWindows.empty())
			return false;

		glfwTerminate();
		return false;
	}

	Window::Window(WindowManager* _WindowManager)
	{

	}

	Window::~Window()
	{

	}
}