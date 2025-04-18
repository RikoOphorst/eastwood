#pragma once

#include "GLFW/glfw3.h"
#include "GLFW/glfw3native.h"

#include "VkBootstrap.h"

#include <vector>

#ifdef CreateWindow
#undef CreateWindow
#endif

namespace eastwood
{
    class Window;

    class WindowManager
    {
        friend class Eastwood;

    protected:
        WindowManager();
        ~WindowManager();

        bool Initialize();
        bool Destroy();

    public:
        static WindowManager* Get();

        Window* CreateWindow();
        const std::vector<Window*>& GetWindows() const;

        void Update();

    private:
        std::vector<Window*> mWindows;
    };

    // A window with an associated surface
    class Window
    {
        friend class WindowManager;
    protected:
        Window(WindowManager* _WindowManager);
        ~Window();

        bool Initialize();

    public:
        bool Destroy();

    private:
        WindowManager* mWindowManager = nullptr;

        GLFWwindow* mWindow = nullptr;
        VkSurfaceKHR mSurface = VK_NULL_HANDLE;
    };
}