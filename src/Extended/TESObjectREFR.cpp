#include "Extended/TESObjectREFR.h"
#include "Offsets.h"

float TESObjectREFREx::GetCurrentSpeed()
{
	using func_t = decltype(&TESObjectREFREx::GetCurrentSpeed);
	REL::Relocation<func_t> func{ TESObjectREFR_GetCurrentSpeed };
	return func(this);
}

void TESObjectREFREx::SetAngleX(float angle)
{
	using func_t = decltype(&TESObjectREFREx::SetAngleX);
	REL::Relocation<func_t> func{ TESObjectREFR_SetAngleX };
	return func(this, angle);
}
