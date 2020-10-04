#ifndef _STREAM_CMD_FACTORY_HPP
#define _STREAM_CMD_FACTORY_HPP


#include "struct_factory.hpp"


namespace {
	constexpr auto STREAM_MODE	= "stream_mode";
	constexpr auto NUM_SAMPS	= "num_samps";
	constexpr auto STREAM_NOW	= "stream_now";
	constexpr auto TIME_SPEC	= "time_spec";
}


template<>
struct StructFactory<uhd::stream_cmd_t> {
	inline static auto createCpp(StructArray const & matlabStructArray) -> uhd::stream_cmd_t {
		auto fields = matlabStructArray.getFieldNames();
		std::unordered_set<std::string> fieldSet{ fields.begin(), fields.end() };
		if (fieldSet.find(STREAM_MODE) == fieldSet.end()) {
			
			//TODO: ERROR
		}
		const matlab::data::Array arr = matlabStructArray[0][STREAM_MODE];
		const int val{ static_cast<int>(arr[0]) };
		uhd::stream_cmd_t::stream_mode_t streamMode{ static_cast<uhd::stream_cmd_t::stream_mode_t>(val) };
		uhd::stream_cmd_t streamCmd{ streamMode };
		streamCmd.stream_now =
			structUtils::TypeConverter<bool>::value(matlabStructArray, STREAM_NOW, fieldSet, streamCmd.stream_now);
		streamCmd.num_samps =
			structUtils::TypeConverter<size_t>::value(matlabStructArray, NUM_SAMPS, fieldSet, streamCmd.num_samps);
		streamCmd.time_spec =
			structUtils::TypeConverter<double>::value(matlabStructArray, TIME_SPEC, fieldSet, streamCmd.time_spec.get_real_secs());
		return streamCmd;
	}

	inline static auto createMatlab(uhd::stream_cmd_t streamCmd) -> matlab::data::StructArray {
		matlab::data::ArrayFactory factory{};
		const matlab::data::ArrayDimensions scalar{ 1, 1 };
		auto retStruct =
			factory.createStructArray(
				scalar,
				{ STREAM_MODE, NUM_SAMPS, TIME_SPEC, STREAM_NOW }
		);
		retStruct[0][STREAM_MODE]	= factory.createScalar(static_cast<int>(streamCmd.stream_mode));
		retStruct[0][NUM_SAMPS]		= factory.createScalar(streamCmd.num_samps);
		retStruct[0][TIME_SPEC]		= factory.createScalar(streamCmd.time_spec.get_real_secs());
		retStruct[0][STREAM_NOW]	= factory.createScalar(streamCmd.stream_now);
		return retStruct;
	}
};

#endif // !_STREAM_CMD_FACTORY_HPP