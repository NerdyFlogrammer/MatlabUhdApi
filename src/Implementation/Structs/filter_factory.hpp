#ifndef _FILTER_FACTORY_HPP
#define _FILTER_FACTORY_HPP

#include "struct_factory.hpp"
#include <uhd/types/filters.hpp>
#include <memory>

namespace {
	const matlab::data::ArrayDimensions SCALAR{ 1, 1 };

	//common
	constexpr auto FILTER_TYPE = "type";
	constexpr auto BYPASSED = "bypassed";

	//common analog
	constexpr auto ANALOG_TYPE = "analog_type";
	const std::vector<std::string> ANALOG_COMMON_FIELDS { FILTER_TYPE, BYPASSED, ANALOG_TYPE } ;

	//analog lp
	constexpr auto CUTOFF = "cutoff";
	constexpr auto ROLLOFF = "rolloff";
	const std::vector<std::string> ANALOG_LP_FIELDS { FILTER_TYPE, BYPASSED, ANALOG_TYPE, CUTOFF, ROLLOFF };

	//common digital
	constexpr auto RATE = "rate";
	constexpr auto INTERPOLATION = "interpolation";
	constexpr auto DECIMATION = "decimation";
	constexpr auto TAP_FULL_SCALE = "tap_full_scale";
	constexpr auto MAX_NUM_TAPS = "max_num_taps";
	constexpr auto TAPS = "taps";
	const std::vector<std::string> DIGITAL_COMMON_FIELDS = {
		FILTER_TYPE, BYPASSED, RATE, INTERPOLATION, 
		DECIMATION, TAP_FULL_SCALE, MAX_NUM_TAPS, TAPS
	};

	//digital fir
	auto DIGITAL_FIR_FIELDS = DIGITAL_COMMON_FIELDS;


}

template<>
struct StructFactory<uhd::filter_info_base> {

	inline static auto createMatlab(uhd::filter_info_base::sptr filterInfo) -> matlab::data::StructArray {
		switch (filterInfo->get_type())
		{
		case uhd::filter_info_base::ANALOG_BAND_PASS:
			return createMatlabAnalogCommon(filterInfo);
		case uhd::filter_info_base::ANALOG_LOW_PASS:
			return createMatlabAnalogLp(filterInfo);
		default:
			std::cout << "not implemented" << std::endl;
			return createMatlabDigitalCommon(filterInfo);
		}
	}


	inline static auto createCpp(StructArray const & matlabStructArray) -> uhd::filter_info_base {

	}
	

private:
	inline static auto createMatlabAnalogCommon(uhd::filter_info_base::sptr filterInfo)->matlab::data::StructArray {
		matlab::data::ArrayFactory factory{};
		auto retStruct =
			factory.createStructArray(
				SCALAR,
				ANALOG_COMMON_FIELDS
		);
		auto analogCommonInfo = boost::dynamic_pointer_cast<uhd::analog_filter_base>(filterInfo);
		retStruct[0][FILTER_TYPE] = factory.createScalar(static_cast<int>(analogCommonInfo->get_type()));
		retStruct[0][BYPASSED] = factory.createScalar(analogCommonInfo->is_bypassed());
		retStruct[0][ANALOG_TYPE] = factory.createCharArray(analogCommonInfo->get_analog_type());
		return retStruct;

	}

	inline static auto createMatlabAnalogLp(uhd::filter_info_base::sptr filterInfo)->matlab::data::StructArray {
		matlab::data::ArrayFactory factory{};
		auto retStruct =
			factory.createStructArray(
				SCALAR,
				ANALOG_LP_FIELDS
			);
		auto analogLpInfo = boost::dynamic_pointer_cast<uhd::analog_filter_lp>(filterInfo);
		retStruct[0][FILTER_TYPE] = factory.createScalar(static_cast<int>(analogLpInfo->get_type()));
		retStruct[0][BYPASSED] = factory.createScalar(analogLpInfo->is_bypassed());
		retStruct[0][ANALOG_TYPE] = factory.createCharArray(analogLpInfo->get_analog_type());
		retStruct[0][CUTOFF] = factory.createScalar(analogLpInfo->get_cutoff());
		retStruct[0][ROLLOFF] = factory.createScalar(analogLpInfo->get_rolloff());
		return retStruct;
	}

	inline static auto createMatlabDigitalCommon(uhd::filter_info_base::sptr filterInfo)->matlab::data::StructArray {
		matlab::data::ArrayFactory factory{};
		auto retStruct =
			factory.createStructArray(
				SCALAR,
				DIGITAL_COMMON_FIELDS
			);

		return retStruct; 
	}

};

#endif // !_STREAM_CMD_FACTORY_HPP