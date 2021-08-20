#pragma once

class OnCustomMarkerChangeRegSet : public RegistrationSet<std::uint32_t>
{
public:
	using Base = SKSE::RegistrationSet<std::uint32_t>;

	static OnCustomMarkerChangeRegSet* GetSingleton();

private:
	OnCustomMarkerChangeRegSet();
	OnCustomMarkerChangeRegSet(const OnCustomMarkerChangeRegSet&) = delete;
	OnCustomMarkerChangeRegSet(OnCustomMarkerChangeRegSet&&) = delete;
	~OnCustomMarkerChangeRegSet() = default;

	OnCustomMarkerChangeRegSet& operator=(const OnCustomMarkerChangeRegSet&) = delete;
	OnCustomMarkerChangeRegSet& operator=(OnCustomMarkerChangeRegSet&&) = delete;
};

class OnFastTravelConfirmRegSet : public RegistrationSet<std::uint32_t>
{
public:
	using Base = SKSE::RegistrationSet<std::uint32_t>;

	static OnFastTravelConfirmRegSet* GetSingleton();

private:
	OnFastTravelConfirmRegSet();
	OnFastTravelConfirmRegSet(const OnFastTravelConfirmRegSet&) = delete;
	OnFastTravelConfirmRegSet(OnFastTravelConfirmRegSet&&) = delete;
	~OnFastTravelConfirmRegSet() = default;

	OnFastTravelConfirmRegSet& operator=(const OnFastTravelConfirmRegSet&) = delete;
	OnFastTravelConfirmRegSet& operator=(OnFastTravelConfirmRegSet&&) = delete;
};
