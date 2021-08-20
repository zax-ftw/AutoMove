#include "Events.h"
#include "Offsets.h"

OnCustomMarkerChangeRegSet* OnCustomMarkerChangeRegSet::GetSingleton()
{
	static OnCustomMarkerChangeRegSet singleton;
	return &singleton;
}

OnCustomMarkerChangeRegSet::OnCustomMarkerChangeRegSet() :
	Base("OnCustomMarkerChange"sv)
{}

OnFastTravelConfirmRegSet* OnFastTravelConfirmRegSet::GetSingleton()
{
	static OnFastTravelConfirmRegSet singleton;
	return &singleton;
}

OnFastTravelConfirmRegSet::OnFastTravelConfirmRegSet() :
	Base("OnFastTravelConfirm"sv)
{}
