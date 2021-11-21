#include "Hooks\CameraState.h"
#include "Hooks\MessageBox.h"
#include "Hooks\AutoMove.h"
#include "Serialization.h"
#include "Papyrus.h"

extern "C" DLLEXPORT bool SKSEAPI SKSEPlugin_Query(const SKSE::QueryInterface* a_skse, SKSE::PluginInfo* a_info)
{
	std::string file = fmt::format("{}.log", PLUGIN_NAME);

	auto path = logger::log_directory().value() / file;
	auto log = spdlog::basic_logger_mt("logger", path.string(), true);

#ifndef NDEBUG
	log->set_level(spdlog::level::trace);
	log->flush_on(spdlog::level::trace);
#else
	log->set_level(spdlog::level::info);
	log->flush_on(spdlog::level::info);
#endif

	spdlog::set_default_logger(log);
	spdlog::set_pattern("[%l] %v");

	logger::info("{} v{}", PLUGIN_NAME, PLUGIN_VERSION);

	a_info->infoVersion = SKSE::PluginInfo::kVersion;
	a_info->name = PLUGIN_NAME;
	a_info->version = VERSION_MAJOR;

	if (a_skse->IsEditor()) {
		logger::critical("Loaded in editor, marking as incompatible"sv);
		return false;
	}

	const auto ver = a_skse->RuntimeVersion();
	if (ver < SKSE::RUNTIME_1_5_39) {
		logger::critical("Unsupported runtime version {}", ver.string());
		return false;
	}

	return true;
}

extern "C" DLLEXPORT bool SKSEAPI SKSEPlugin_Load(const SKSE::LoadInterface* a_skse)
{
	logger::info("Loading...");

	SKSE::Init(a_skse);
	SKSE::AllocTrampoline(64);

	auto papyrus = SKSE::GetPapyrusInterface();
	papyrus->Register(Papyrus::RegisterFuncs);

	auto serialization = SKSE::GetSerializationInterface();
	serialization->SetUniqueID(Serialization::kAutoWalk);
	serialization->SetSaveCallback(Serialization::SaveCallback);
	serialization->SetLoadCallback(Serialization::LoadCallback);
	serialization->SetRevertCallback(Serialization::RevertCallback);

	CameraStateHook::Install();
	PlaceMarkerHook::Install();
	AutoMoveHook::Install();

	return true;
}
