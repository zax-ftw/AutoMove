#pragma once

namespace RE
{
	namespace Offset
	{
		namespace ThirdPersonState
		{
			constexpr REL::ID SetFreeRotationMode{ 49968 };  // 0x0084fa20
			constexpr REL::ID HandleRotationX{ 49907 };      // 0x0084d3c0
		}

		namespace HorseCameraState
		{
			constexpr REL::ID UpdateRotation{ 49840 };   // 0x00849a70
			constexpr REL::ID HandleLookInput{ 49839 };  // 0x00849930
		}

		namespace DragonCameraState
		{
			constexpr REL::ID UpdateRotation{ 32371 };  // 0x004f9800
		}

		namespace TESObjectREFR
		{
			constexpr REL::ID GetCurrentSpeed{ 36932 };  // 0x00608c60
			constexpr REL::ID SetAngleX{ 36602 };        // 0x005edd50
		}

		namespace PlacePlayerMarkerCallbackFunctor
		{
			constexpr REL::ID Vtbl{ 270842 };  // 0x016c3568
		}

		namespace FastTravelConfirmCallback
		{
			constexpr REL::ID Vtbl{ 270844 };  // 0x016C35A0
		}
	}

}
