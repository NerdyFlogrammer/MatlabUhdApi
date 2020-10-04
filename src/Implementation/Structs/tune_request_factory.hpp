#ifndef _TUNE_REQUEST_FACTORY_
#define _TUNE_REQUEST_FACTORY_

#include "struct_factory.hpp"
#include <uhd/types/tune_request.hpp>

namespace {
		constexpr auto TARGET_FREQ		= "target_freq";
		constexpr auto RF_FREQ_POLICY	= "rf_freq_policy";
		constexpr auto RF_FREQ			= "rf_freq";
		constexpr auto DSP_FREQ_POLICY	= "dsp_freq_policy";
		constexpr auto DSP_FREQ			= "dsp_freq";
		constexpr auto ARGS				= "args";
}


template<>
struct StructFactory<uhd::tune_request_t> {
	inline static auto createCpp(StructArray const & matlabStructArray) -> uhd::tune_request_t {
		uhd::tune_request_t tuneRequest{};
		auto fields = matlabStructArray.getFieldNames();
		std::unordered_set<std::string> fieldset{ fields.begin(), fields.end() };
		tuneRequest.target_freq =
			structUtils::TypeConverter<double>::value(matlabStructArray, TARGET_FREQ, fieldset, tuneRequest.target_freq);
		tuneRequest.rf_freq_policy =
			structUtils::TypeConverter<uhd::tune_request_t::policy_t>::value(matlabStructArray, RF_FREQ_POLICY, fieldset, tuneRequest.rf_freq_policy);
		tuneRequest.rf_freq =
			structUtils::TypeConverter<double>::value(matlabStructArray, RF_FREQ, fieldset, tuneRequest.rf_freq);
		tuneRequest.dsp_freq_policy =
			structUtils::TypeConverter<uhd::tune_request_t::policy_t>::value(matlabStructArray, DSP_FREQ_POLICY, fieldset, tuneRequest.dsp_freq_policy);
		tuneRequest.dsp_freq =
			structUtils::TypeConverter<double>::value(matlabStructArray, DSP_FREQ, fieldset, tuneRequest.dsp_freq);
		//TODO: args !!!
		return tuneRequest;
	}

	inline static auto createMatlab(uhd::tune_request_t tr) -> matlab::data::StructArray {
		ArrayFactory factory{};
		const matlab::data::ArrayDimensions scalar{ 1, 1 };
		auto retStruct =
			factory.createStructArray(
				scalar,
				{ TARGET_FREQ, RF_FREQ_POLICY,  RF_FREQ, DSP_FREQ_POLICY, DSP_FREQ }
		);
		retStruct[0][TARGET_FREQ] = factory.createScalar(tr.target_freq);
		retStruct[0][RF_FREQ_POLICY] = factory.createScalar(static_cast<int32_t>(tr.rf_freq_policy));
		retStruct[0][RF_FREQ] = factory.createScalar(tr.rf_freq);
		retStruct[0][DSP_FREQ_POLICY] = factory.createScalar(static_cast<int32_t>(tr.dsp_freq_policy));
		retStruct[0][DSP_FREQ] = factory.createScalar(tr.dsp_freq);
		//TODO: ARGS
		return retStruct;
	}
};

#endif