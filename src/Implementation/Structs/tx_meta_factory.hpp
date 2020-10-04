#ifndef _TX_META_STRUCT_FACTORY_HPP_
#define _TX_META_STRUCT_FACTORY_HPP_

#include "struct_factory.hpp"
#include <uhd/types/metadata.hpp>

namespace TX_META {
		constexpr auto HAS_TIME_SPEC		= "has_time_spec";
		constexpr auto TIME_SPEC			= "time_spec";
		constexpr auto START_OF_BURST		= "start_of_burst";
		constexpr auto END_OF_BURST			= "end_of_burst";
}


template<>
struct StructFactory<uhd::tx_metadata_t> {
	inline static auto createCpp(StructArray const & matlabStructArray) -> uhd::tx_metadata_t {
		uhd::tx_metadata_t metaData{};
		auto fields = matlabStructArray.getFieldNames();
		std::unordered_set<std::string> fieldset{ fields.begin(), fields.end() };
		metaData.has_time_spec =
			structUtils::TypeConverter<bool>::value(matlabStructArray, TX_META::HAS_TIME_SPEC, fieldset, metaData.has_time_spec);
		metaData.time_spec =
			structUtils::TypeConverter<double>::value(matlabStructArray, TX_META::TIME_SPEC, fieldset, metaData.time_spec.get_real_secs());
		metaData.start_of_burst =
			structUtils::TypeConverter<bool>::value(matlabStructArray, TX_META::START_OF_BURST, fieldset, metaData.start_of_burst);
		metaData.end_of_burst =
			structUtils::TypeConverter<bool>::value(matlabStructArray, TX_META::END_OF_BURST, fieldset, metaData.end_of_burst);
		return metaData;
	}

	inline static auto createMatlab(uhd::tx_metadata_t md) -> matlab::data::StructArray {
		ArrayFactory factory{};
		const matlab::data::ArrayDimensions scalar{ 1, 1 };
		auto retStruct =
			factory.createStructArray(
				scalar,
				{ TX_META::HAS_TIME_SPEC, TX_META::TIME_SPEC,  TX_META::START_OF_BURST, TX_META::END_OF_BURST }
		);
		retStruct[0][TX_META::HAS_TIME_SPEC] = factory.createScalar(md.has_time_spec);
		retStruct[0][TX_META::TIME_SPEC] = factory.createScalar(md.time_spec.get_real_secs());
		retStruct[0][TX_META::START_OF_BURST] = factory.createScalar(md.start_of_burst);
		retStruct[0][TX_META::END_OF_BURST] = factory.createScalar(md.end_of_burst);
		return retStruct;
	}
};

#endif // !_TX_META_STRUCT_FACTORY_HPP