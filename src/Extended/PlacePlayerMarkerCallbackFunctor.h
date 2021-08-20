#pragma once

class PlacePlayerMarkerCallbackFunctor : public IMessageBoxCallback
{
public:
	inline static constexpr auto RTTI = RTTI___PlacePlayerMarkerCallbackFunctor;

	virtual ~PlacePlayerMarkerCallbackFunctor();  // 00

	// override (IMessageBoxCallback)
	virtual void Run(Message a_msg) override;  // 01

	// members
	MapMenu* subMenu;  // 10
};
