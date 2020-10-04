#ifndef _ASYNC_METADATA_STRUCT_FACTORY_HPP
#define _ASYNC_METADATA_STRUCT_FACTORY_HPP

#include "struct_factory.hpp"
#include <uhd/types/metadata.hpp>

namespace {
	constexpr auto CHANNEL = "channel";
	constexpr auto HAS_TIME_SPEC = "has_time_spec";
	//constexpr auto TIME_SPEC = "time_spec";
	constexpr auto EVENT_CODE = "event_code";
	constexpr auto USER_PAYLOAD = "user_payload";
}


template<>
struct StructFactory<uhd::async_metadata_t> {
	inline static auto createCpp(StructArray const & matlabStructArray) -> uhd::async_metadata_t {
		uhd::async_metadata_t metaData{};
		auto fields = matlabStructArray.getFieldNames();
		std::unordered_set<std::string> fieldSet{ fields.begin(), fields.end() };
		metaData.channel =
			structUtils::TypeConverter<size_t>::value(matlabStructArray, CHANNEL, fieldSet, metaData.channel);
		metaData.has_time_spec =
			structUtils::TypeConverter<bool>::value(matlabStructArray, HAS_TIME_SPEC, fieldSet, metaData.has_time_spec);
		metaData.time_spec =
			structUtils::TypeConverter<double>::value(matlabStructArray, TIME_SPEC, fieldSet, metaData.time_spec.get_real_secs());
		metaData.event_code =
			structUtils::TypeConverter<uhd::async_metadata_t::event_code_t>::value(matlabStructArray, EVENT_CODE, fieldSet, metaData.event_code);
		if (fieldSet.find(USER_PAYLOAD) != fieldSet.end()) {
			const Array playloadArr = matlabStructArray[0][USER_PAYLOAD];
			for (int i = 0; i < 4; i++)
			{
				metaData.user_payload[i] = static_cast<uint32_t>(playloadArr[i]);
			}
		}
		return metaData;
	}

	inline static auto createMatlab(uhd::async_metadata_t md) -> matlab::data::StructArray {
		matlab::data::ArrayFactory factory{};
		const matlab::data::ArrayDimensions scalar{ 1, 1 };
		auto retStruct =
			factory.createStructArray(
				scalar,
				{ CHANNEL, HAS_TIME_SPEC, TIME_SPEC, EVENT_CODE, USER_PAYLOAD }
		);
		retStruct[0][CHANNEL] = factory.createScalar(md.channel);
		retStruct[0][HAS_TIME_SPEC] = factory.createScalar(md.has_time_spec);
		retStruct[0][TIME_SPEC] = factory.createScalar(md.has_time_spec);
		retStruct[0][EVENT_CODE] = factory.createScalar(static_cast<int32_t>(md.event_code));
		const matlab::data::ArrayDimensions dimPayload{ 1, 4 };
		retStruct[0][USER_PAYLOAD] = factory.createArray(dimPayload, std::begin(md.user_payload), std::end(md.user_payload));
		return retStruct;
	}
};

#endif // !_ASYNC_METADATA_STRUCT_FACTORY_HPP