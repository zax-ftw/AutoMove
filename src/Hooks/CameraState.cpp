#include "Hooks/CameraState.h"
#include "Offsets.h"

float CameraStateHook::GetCurrentSpeed_Hook()
{
	PlayerCharacter* player = PlayerCharacter::GetSingleton();

	if (player->unkBDA & FlagBDA::kAIDriven) {
		return 0.0;
	}
	return GetCurrentSpeed();
}

float CameraStateHook::GetAngleX_Hook()
{
	PlayerCharacter* player = PlayerCharacter::GetSingleton();

	return player->data.angle.x;
}

void CameraStateHook::ModAngleX_Hook(float angle)
{
	PlayerCharacter* player = PlayerCharacter::GetSingleton();

	SetAngleX(player->data.angle.x + angle);
}

void CameraStateHook::Install()
{
	REL::Relocation<std::uintptr_t> GetCurrentSpeed_Call1{ DragonCameraState_UpdateRotation, 0x92 };
	REL::Relocation<std::uintptr_t> GetCurrentSpeed_Call2{ HorseCameraState_UpdateRotation, 0x84 };
	REL::Relocation<std::uintptr_t> GetCurrentSpeed_Call3{ ThirdPersonState_SetFreeRotationMode, 0x43 };

	REL::Relocation<std::uintptr_t> GetAngleX_Call1{ HorseCameraState_HandleLookInput, 0x97 };
//	REL::Relocation<std::uintptr_t> GetAngleX_Call2{ ThirdPersonState_HandleRotationX, 0x20C };
//	REL::Relocation<std::uintptr_t> SetAngleX_Call1{ ThirdPersonState_HandleRotationX, 0x217 };
	REL::Relocation<std::uintptr_t> ModAngleX_Call1{ ThirdPersonState_HandleRotationX, 0x1FD };

	auto& trampoline = SKSE::GetTrampoline();

	trampoline.write_call<5>(GetCurrentSpeed_Call1.address(), &CameraStateHook::GetCurrentSpeed_Hook);
	trampoline.write_call<5>(GetCurrentSpeed_Call2.address(), &CameraStateHook::GetCurrentSpeed_Hook);
	trampoline.write_call<5>(GetCurrentSpeed_Call3.address(), &CameraStateHook::GetCurrentSpeed_Hook);

	trampoline.write_call<5>(GetAngleX_Call1.address(), &CameraStateHook::GetAngleX_Hook);
//	trampoline.write_call<5>(GetAngleX_Call2.address(), &CameraStateHook::GetAngleX_Hook);
//	trampoline.write_call<5>(SetAngleX_Call1.address(), &CameraStateHook::SetAngleX_Hook);
	trampoline.write_call<5>(ModAngleX_Call1.address(), &CameraStateHook::ModAngleX_Hook);

	logger::info("Camera hooks installed");
}
