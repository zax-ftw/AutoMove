#include "Hooks/MessageBox.h"
#include "Offsets.h"
#include "Events.h"

// 0 move, 1 leave, 2 remove
void PlaceMarkerHook::Run(PlacePlayerMarkerCallbackFunctor* a_this, Message a_msg)
{
	logger::trace("PlaceMarkerHook: {}", a_msg);

	OnCustomMarkerChangeRegSet::GetSingleton()->QueueEvent(
		static_cast<std::underlying_type_t<Message>>(a_msg));

	_Run(a_this, a_msg);
}

// 0 unk, 1 yes, 2 no, 3 marker
void FastTravelHook::Run(FastTravelConfirmCallback* a_this, Message a_msg)
{
	logger::trace("FastTravelHook: {}", a_msg);

	_Run(a_this, a_msg);
}

void PlaceMarkerHook::Install()
{
	Relocation<std::uintptr_t> vtbl{ PlacePlayerMarkerCallbackFunctor_Vtbl };
	_Run = vtbl.write_vfunc(0x2, Run);
};

void FastTravelHook::Install()
{
	Relocation<std::uintptr_t> vtbl{ FastTravelConfirmCallback_Vtbl };
	_Run = vtbl.write_vfunc(0x2, Run);
};
