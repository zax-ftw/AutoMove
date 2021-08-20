
namespace Papyrus
{
	void ForceDestinationMarkerIntoAliasID(TESQuest* quest, std::uint32_t index);
	Actor* GetCurrentMount(StaticFunctionTag*, Actor* actor);
	bool IsCustomDestinationActive(StaticFunctionTag*);
	void RegisterForCustomMarkerChange(TESQuest* quest);
	void UnregisterForCustomMarkerChange(TESQuest* quest);
	bool RegisterFuncs(BSScript::IVirtualMachine* a_vm);
}
