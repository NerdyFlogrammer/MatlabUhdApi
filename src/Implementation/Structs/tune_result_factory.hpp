#ifndef _TUNE_RESULT_FACTORY_
#define _TUNE_RESULT_FACTORY_

#include "struct_factory.hpp"
#include <uhd/types/tune_result.h>

namespace {
	constexpr auto CLIPPED_RF_FREQ = "clipped_rf_freq";
	constexpr auto TARGET_RF_FREQ = "target_rf_freq";
	constexpr auto ACTUAL_RF_FREQ = "actual_rf_freq";
	constexpr auto TARGET_DSP_FREQ = "target_dsp_freq";
	constexpr auto ACTUAL_DSP_FREQ = "actual_dsp_freq";		
}


template<>
struct StructFactory<uhd::tune_result_t> {
	inline static auto createCpp(StructArray const & matlabStructArray) -> uhd::tune_result_t {
		uhd::tune_result_t tr{};
		auto fields = matlabStructArray.getFieldNames();
		std::unordered_set<std::string> fieldset{ fields.begin(), fields.end() };
		tr.clipped_rf_freq =
			structUtils::TypeConverter<double>::value(matlabStructArray, CLIPPED_RF_FREQ, fieldset, tr.clipped_rf_freq);
		tr.target_rf_freq =
			structUtils::TypeConverter<double>::value(matlabStructArray, TARGET_RF_FREQ, fieldset, tr.target_rf_freq);
		tr.actual_rf_freq =
			structUtils::TypeConverter<double>::value(matlabStructArray, ACTUAL_RF_FREQ, fieldset, tr.actual_rf_freq);
		tr.target_dsp_freq =
			structUtils::TypeConverter<double>::value(matlabStructArray, TARGET_DSP_FREQ, fieldset, tr.target_dsp_freq);
		tr.actual_dsp_freq =
			structUtils::TypeConverter<double>::value(matlabStructArray, ACTUAL_DSP_FREQ, fieldset, tr.actual_dsp_freq);
		return tr;
	}

	inline static auto createMatlab(uhd::tune_result_t tr) -> matlab::data::StructArray {
		ArrayFactory factory{};
		const matlab::data::ArrayDimensions scalar{ 1, 1 };
		auto retStruct =
			factory.createStructArray(
				scalar,
				{ CLIPPED_RF_FREQ, TARGET_RF_FREQ,  ACTUAL_RF_FREQ, TARGET_DSP_FREQ, ACTUAL_DSP_FREQ }
		);
		retStruct[0][CLIPPED_RF_FREQ] = factory.createScalar(tr.clipped_rf_freq);
		retStruct[0][TARGET_RF_FREQ] = factory.createScalar(tr.target_rf_freq);
		retStruct[0][ACTUAL_RF_FREQ] = factory.createScalar(tr.actual_rf_freq);
		retStruct[0][TARGET_DSP_FREQ] = factory.createScalar(tr.target_dsp_freq);
		retStruct[0][ACTUAL_DSP_FREQ] = factory.createScalar(tr.actual_dsp_freq);
		return retStruct;
	}
};

#endif