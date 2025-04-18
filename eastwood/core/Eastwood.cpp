#include "core/Eastwood.h"

#include "core/RenderPlatform.h"
#include "core/WindowManager.h"

namespace eastwood
{
	Eastwood* gEastwoodInstance = nullptr;

	Eastwood::~Eastwood()
	{

	}
	
	Eastwood* Eastwood::Instance()
	{
		if (gEastwoodInstance == nullptr)
			return false;

		return nullptr;
	}

	bool Eastwood::Initialize()
	{
		mRenderPlatform = new RenderPlatform();
		mWindowManager = new WindowManager();


	}

	bool Eastwood::Shutdown()
	{
		return false;
	}
	
	RenderPlatform* Eastwood::GetRenderPlatform() const
	{
		assert(mRenderPlatform != nullptr);
		return mRenderPlatform;
	}
	
	WindowManager* Eastwood::GetWindowManager() const
	{
		assert(mWindowManager != nullptr);
		return mWindowManager;
	}
}