#include "Serialization.h"
#include "Events.h"

namespace Serialization
{
	std::string DecodeTypeCode(uint32_t a_typeCode)
	{
		constexpr std::size_t SIZE = sizeof(uint32_t);

		std::string sig;
		sig.resize(SIZE);
		const char* iter = reinterpret_cast<char*>(&a_typeCode);
		for (std::size_t i = 0, j = SIZE - 1; i < SIZE; ++i, --j) {
			sig[j] = iter[i];
		}

		return sig;
	}

	void SaveCallback(SKSE::SerializationInterface* a_intfc)
	{
		Save<OnCustomMarkerChangeRegSet>(a_intfc, kMarkerChange);
		Save<OnFastTravelConfirmRegSet>(a_intfc, kFastTravel);

		logger::info("Finished saving data"sv);
	}

	void LoadCallback(SKSE::SerializationInterface* a_intfc)
	{
		uint32_t type, version, length;

		while (a_intfc->GetNextRecordInfo(type, version, length)) {
			if (version != kVersion) {
				logger::critical("Loaded data is out of date! Read ({}), expected ({}) for type code ({})", version, kVersion, DecodeTypeCode(type));
				continue;
			}
			switch (type) {
			case kMarkerChange:
				Load<OnCustomMarkerChangeRegSet>(a_intfc);
				break;
			case kFastTravel:
				Load<OnFastTravelConfirmRegSet>(a_intfc);
				break;
			default:
				logger::critical("Unrecognized record type ({})!"sv, DecodeTypeCode(type));
				break;
			}
		}
		logger::info("Finished loading data"sv);
	}

	void RevertCallback(SKSE::SerializationInterface* a_intfc)
	{
		Revert<OnCustomMarkerChangeRegSet>(a_intfc);
		Revert<OnFastTravelConfirmRegSet>(a_intfc);

		logger::info("Finished reverting data"sv);
	}
}
