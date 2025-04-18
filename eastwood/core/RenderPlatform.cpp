#include "core/RenderPlatform.h"

namespace eastwood
{
    RenderPlatform* gRenderPlatformInstance = 

    bool RenderPlatform::SetInstance(RenderPlatform* _Instance)
    {
        return false;
    }
    RenderPlatform* RenderPlatform::Instance()
    {
        return nullptr;
    }
    RenderPlatform::RenderPlatform()
	{
	}

	RenderPlatform::~RenderPlatform()
	{
	}

	RenderPlatform* RenderPlatform::Get()
	{
		static RenderPlatform* platform = new RenderPlatform();

		if (platform == nullptr)
		{
			platform = new RenderPlatform();
		}

		return platform;
	}

	bool RenderPlatform::Initialize()
	{
        vkb::InstanceBuilder instanceBuilder;

        instanceBuilder.set_app_name("Eastwood");
        instanceBuilder.set_engine_name("Eastwood");
        instanceBuilder.use_default_debug_messenger();
        instanceBuilder.request_validation_layers();

        auto instanceBuildResult = instanceBuilder.build();

        if (!instanceBuildResult)
        {
            printf("Failed to build Vulkan Instance.\n");
            return -1;
        }

        vkb::Instance instance = instanceBuildResult.value();

        vkb::PhysicalDeviceSelector physicalDeviceSelector{ instance };
        physicalDeviceSelector.prefer_gpu_device_type(vkb::PreferredDeviceType::discrete);
        physicalDeviceSelector.disable_portability_subset();
        physicalDeviceSelector.defer_surface_initialization();
        physicalDeviceSelector.set_minimum_version(1, 4);
        physicalDeviceSelector.require_present();
        physicalDeviceSelector.require_separate_compute_queue();
        physicalDeviceSelector.require_dedicated_transfer_queue();

        auto deviceSelectResult = physicalDeviceSelector.select();

        if (!deviceSelectResult)
        {
            printf("Failed to select a Physical Device.\n");
            return -1;
        }

        vkb::PhysicalDevice physicalDevice = deviceSelectResult.value();
        vkb::DeviceBuilder deviceBuilder(physicalDevice);

        auto deviceBuildResult = deviceBuilder.build();

        vkb::DeviceBuilder device_builder{ phys_ret.value() };
        auto dev_ret = device_builder.build();
        if (!dev_ret) { /* report */ }
        vkb::Device vkb_device = dev_ret.value();

        auto graphics_queue_ret = vkb_device.get_queue(vkb::QueueType::graphics);
        if (!graphics_queue_ret) { /* report */ }
        VkQueue graphics_queue = graphics_queue_ret.value();

		return true;
	}

    bool RenderPlatform::Destroy()
    {
        return false;
    }
}
