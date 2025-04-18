#pragma once

#include "VkBootstrap.h"

namespace eastwood
{
    class RenderPlatform
    {
        friend class Eastwood;

    protected:
        static bool SetInstance(RenderPlatform* _Instance);

    public:
        static RenderPlatform* Instance();

        RenderPlatform();
        ~RenderPlatform();

        bool Initialize();
        bool Destroy();

    private:
        bool mInitialized = false;
        
        vkb::Instance       mInstance = {};
        vkb::PhysicalDevice mPhysicalDevice = {};
        vkb::Device         mDevice = {};

    };
}