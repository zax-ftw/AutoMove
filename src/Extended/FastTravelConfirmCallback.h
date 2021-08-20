#pragma once

class FastTravelConfirmCallback : public IMessageBoxCallback
{
public:
	inline static constexpr auto RTTI = RTTI___FastTravelConfirmCallback;

	virtual ~FastTravelConfirmCallback();  // 00

	// override (IMessageBoxCallback)
	virtual void Run(Message a_msg) override;  // 01

	// members
	MapMenu* subMenu;  // 10
};
