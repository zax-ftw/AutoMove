
namespace Papyrus
{
	void ForceDestinationMarkerIntoAliasID(TESQuest* quest, std::uint32_t index);
	Actor* GetCurrentMount(StaticFunctionTag*, Actor* actor);
	bool IsCustomDestinationActive(StaticFunctionTag*);
	bool RegisterFuncs(BSScript::IVirtualMachine* a_vm);
}
