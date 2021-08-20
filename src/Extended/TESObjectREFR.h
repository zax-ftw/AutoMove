class TESObjectREFREx : public TESObjectREFR
{
public:

	enum FlagBDA // enum class - PlayerCharacter.h
	{
		kAIDriven = 0x08 // 1 << 3
	};

	float GetCurrentSpeed();
	void SetAngleX(float angle);
};

