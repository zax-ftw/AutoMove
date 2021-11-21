#pragma once

namespace Serialization
{
	constexpr uint32_t kVersion = 1;

	enum : uint32_t
	{
		kAutoWalk = 'ATMV',

		kMarkerChange = 'CHNG',
		kFastTravel = 'TRVL'
	};

	void SaveCallback(SKSE::SerializationInterface* a_intfc);
	void LoadCallback(SKSE::SerializationInterface* a_intfc);
	void RevertCallback(SKSE::SerializationInterface* a_intfc);

	template <class T>
	void Save(SKSE::SerializationInterface* a_intfc, std::uint32_t a_type)
	{
		const auto regs = T::GetSingleton();
		if (!regs->Save(a_intfc, a_type, kVersion)) {
			logger::critical("Failed to save {} regs!"sv, typeid(T).name());
		}
	}

	template <class T>
	void Load(SKSE::SerializationInterface* a_intfc)
	{
		const auto regs = T::GetSingleton();
		if (!regs->Load(a_intfc)) {
			logger::critical("Failed to load {} regs!"sv, typeid(T).name());
		}
	}

	template <class T>
	void Revert(SKSE::SerializationInterface*)
	{
		const auto regs = T::GetSingleton();
		regs->Clear();
	}
}
