#include "Extended/TESObjectREFR.h"

class CameraStateHook : public TESObjectREFREx
{
public:
	static void Install();

private:

	float GetCurrentSpeed_Hook();
	float GetAngleX_Hook();
	void ModAngleX_Hook(float angle);
};

