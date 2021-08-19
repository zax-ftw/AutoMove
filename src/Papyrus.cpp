#include "Papyrus.h"

namespace Papyrus
{
	void ForceDestinationMarkerIntoAliasID(TESQuest* quest, std::uint32_t index)
	{
		PlayerCharacter* player = PlayerCharacter::GetSingleton();

		NiPointer<TESObjectREFR> marker;
		TESObjectREFR::LookupByHandle(player->unk924, marker);

		if (marker) {
			quest->ForceRefIntoAliasID(index, marker.get());
		}
	}

	Actor* GetCurrentMount(StaticFunctionTag*, Actor* actor)
	{
		ExtraInteraction* extra = static_cast<ExtraInteraction*>(actor->extraList.GetByType(ExtraDataType::kInteraction));
		if (extra) {
			NiPointer<Actor> mount = extra->interaction->actor.get();
			if (mount) {
				return mount.get();
			}
		}
		return nullptr;
	}

	bool IsCustomDestinationActive(StaticFunctionTag*)
	{
		PlayerCharacter* player = PlayerCharacter::GetSingleton();
		return player->unk924 ? true : false;
	}

	bool RegisterFuncs(BSScript::IVirtualMachine* a_vm)
	{
		a_vm->RegisterFunction("ForceDestinationMarkerIntoAliasID", "AutoWalk", ForceDestinationMarkerIntoAliasID);
		a_vm->RegisterFunction("IsCustomDestinationActive", "AutoWalk", IsCustomDestinationActive);
		a_vm->RegisterFunction("GetCurrentMount", "AutoWalk", GetCurrentMount);		

		logger::info("Papyrus functions registered");

		return true;
	}
}
