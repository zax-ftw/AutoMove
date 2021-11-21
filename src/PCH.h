#pragma once

#include "RE/Skyrim.h"
#include "SKSE/SKSE.h"

#include <type_traits>

#include <spdlog/sinks/basic_file_sink.h>

using namespace std::literals;

using namespace SKSE;
using namespace RE;
using namespace REL;

namespace logger = SKSE::log;

#define DLLEXPORT __declspec(dllexport)

#include "config.h"
