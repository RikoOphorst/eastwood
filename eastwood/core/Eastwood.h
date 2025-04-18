#pragma once

namespace eastwood
{
    class RenderPlatform;
    class WindowManager;

    class Eastwood
    {
    private:
        Eastwood();
        ~Eastwood();

    public:
        static Eastwood* Instance();

        bool Initialize();
        bool Shutdown();

        RenderPlatform* GetRenderPlatform() const;
        WindowManager* GetWindowManager() const;

    public:
        void BeginFrame();
        void EndFrame();

    private:
        RenderPlatform* mRenderPlatform = nullptr;
        WindowManager* mWindowManager = nullptr;
    };
}