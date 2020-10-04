#ifndef _RX_META_STRUCT_FACTORY_HPP
#define _RX_META_STRUCT_FACTORY_HPP

#include "struct_factory.hpp"
#include <uhd/types/metadata.hpp>


template<>
struct StructFactory<uhd::rx_metadata_t> {
	inline static uhd::rx_metadata_t createCpp(StructArray const & matlabStructArray) {
		uhd::rx_metadata_t metaData{};
		auto fields = matlabStructArray.getFieldNames();
		std::unordered_set<std::string> fieldSet{ fields.begin(), fields.end() };
		metaData.start_of_burst =
			structUtils::TypeConverter<bool>::value(matlabStructArray, "start_of_burst", fieldSet, metaData.start_of_burst);
		metaData.end_of_burst =
			structUtils::TypeConverter<bool>::value(matlabStructArray, "end_of_burst", fieldSet, metaData.end_of_burst);
		metaData.has_time_spec =
			structUtils::TypeConverter<bool>::value(matlabStructArray, "has_time_spec", fieldSet, metaData.has_time_spec);
		metaData.error_code =
			structUtils::TypeConverter<uhd::rx_metadata_t::error_code_t>::value(matlabStructArray, "error_code", fieldSet, metaData.error_code);
		metaData.more_fragments =
			structUtils::TypeConverter<bool>::value(matlabStructArray, "more_fragments", fieldSet, metaData.more_fragments);
		metaData.time_spec =
			structUtils::TypeConverter<double>::value(matlabStructArray, "time_spec", fieldSet, metaData.time_spec.get_real_secs());
		metaData.out_of_sequence =
			structUtils::TypeConverter<bool>::value(matlabStructArray, "out_of_sequence", fieldSet, metaData.out_of_sequence);
		return metaData;
	}

	inline static auto createMatlab(uhd::rx_metadata_t md) -> matlab::data::StructArray {
		matlab::data::ArrayFactory factory{};
		const matlab::data::ArrayDimensions scalar{ 1, 1 };
		auto retStruct =
			factory.createStructArray(
				scalar,
				{ "start_of_burst", "end_of_burst", "has_time_spec", "error_code",
				"more_fragments", "time_spec", "out_of_sequence" }
		);
		retStruct[0]["start_of_burst"] = factory.createScalar(md.start_of_burst);
		retStruct[0]["end_of_burst"] = factory.createScalar(md.end_of_burst);
		retStruct[0]["has_time_spec"] = factory.createScalar(md.has_time_spec);
		retStruct[0]["error_code"] = factory.createScalar(static_cast<int32_t>(md.error_code));
		retStruct[0]["more_fragments"] = factory.createScalar(md.more_fragments);
		retStruct[0]["time_spec"] = factory.createScalar(md.time_spec.get_real_secs());
		retStruct[0]["out_of_sequence"] = factory.createScalar(md.out_of_sequence);
		return retStruct;
	}
};

#endif // !_RX_META_STRUCT_FACTORY_HPP