#pragma once

class AutoMoveHook : public AutoMoveHandler
{
public:
	static void Install();

private:
	static bool CanProcess(AutoMoveHandler* a_this, InputEvent* a_event);
	static inline REL::Relocation<decltype(CanProcess)> _CanProcess;
};
