#include "Hooks\AutoMove.h"

bool AutoMoveHook::CanProcess(AutoMoveHandler* a_this, InputEvent* a_event)
{
	PlayerCharacter* player = PlayerCharacter::GetSingleton();
	return _CanProcess(a_this, a_event) && (!player->unk924);
}

void AutoMoveHook::Install()
{
	Relocation<std::uintptr_t> vtbl{ RE::Offset::AutoMoveHandler::Vtbl };
	_CanProcess = vtbl.write_vfunc(0x1, CanProcess);
};
