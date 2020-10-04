#ifndef _REGISTER_INFO_FACTORY_HPP_
#define _REGISTER_INFO_FACTORY_HPP_

#include "struct_factory.hpp"
#include <uhd/usrp/multi_usrp.hpp>usrp

namespace {
	constexpr auto BITWIDTH = "bitwidth";
	constexpr auto READABLE = "readable";
	constexpr auto WRITABLE = "writable";
}


template<>
struct StructFactory<uhd::usrp::multi_usrp::register_info_t> {
	inline static auto createCpp(StructArray const & matlabStructArray) -> uhd::usrp::multi_usrp::register_info_t {
		auto fields = matlabStructArray.getFieldNames();
		std::unordered_set<std::string> fieldSet{ fields.begin(), fields.end() };
		uhd::usrp::multi_usrp::register_info_t regInfo{ };
		regInfo.bitwidth =
			structUtils::TypeConverter<size_t>::value(matlabStructArray, BITWIDTH, fieldSet, regInfo.bitwidth);
		regInfo.readable =
			structUtils::TypeConverter<bool>::value(matlabStructArray, READABLE, fieldSet, regInfo.readable);
		regInfo.writable =
			structUtils::TypeConverter<bool>::value(matlabStructArray, WRITABLE, fieldSet, regInfo.writable);
		return regInfo;
	}

	inline static auto createMatlab(uhd::usrp::multi_usrp::register_info_t registerInfo) -> matlab::data::StructArray {
		matlab::data::ArrayFactory factory{};
		const matlab::data::ArrayDimensions scalar{ 1, 1 };
		auto retStruct =
			factory.createStructArray(
				scalar,
				{ BITWIDTH, READABLE, WRITABLE }
		);
		retStruct[0][BITWIDTH] = factory.createScalar(registerInfo.bitwidth);
		retStruct[0][READABLE] = factory.createScalar(registerInfo.readable);
		retStruct[0][WRITABLE] = factory.createScalar(registerInfo.writable);

		return retStruct;
	}
};

#endif // !_STREAM_ARGS_STRUCT_HPP_