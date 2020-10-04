#ifndef _SPECIAL_PROPS_T_FACTORY_HPP_
#define _SPECIAL_PROPS_T_FACTORY_HPP_

#include "struct_factory.hpp"
#include <uhd/usrp/dboard_iface.hpp>

namespace {
	constexpr auto SOFT_CLOCK_DIVIDER = "soft_clock_divider";
	constexpr auto MANGLE_I2C_ADDRS = "mangle_i2c_addrs";
}

template<>
struct StructFactory<uhd::usrp::dboard_iface_special_props_t> {
	inline static auto createCpp(StructArray const & matlabStructArray) -> uhd::usrp::dboard_iface_special_props_t {
		uhd::usrp::dboard_iface_special_props_t sp{};
		auto fields = matlabStructArray.getFieldNames();
		std::unordered_set<std::string> fieldset{ fields.begin(), fields.end() };
		sp.soft_clock_divider = 
			structUtils::TypeConverter<bool>::value(matlabStructArray, SOFT_CLOCK_DIVIDER, fieldset, sp.soft_clock_divider);
		sp.mangle_i2c_addrs = 
			structUtils::TypeConverter<bool>::value(matlabStructArray, MANGLE_I2C_ADDRS, fieldset, sp.mangle_i2c_addrs);
		return sp;
	}

	inline static auto createMatlab(uhd::usrp::dboard_iface_special_props_t sp) -> matlab::data::StructArray {
		matlab::data::ArrayFactory factory{};
		const matlab::data::ArrayDimensions scalar{ 1, 1 };
		auto retStruct =
			factory.createStructArray(
				scalar,
				{ SOFT_CLOCK_DIVIDER, MANGLE_I2C_ADDRS }
		);
		retStruct[0][SOFT_CLOCK_DIVIDER] = factory.createScalar(sp.soft_clock_divider);
		retStruct[0][MANGLE_I2C_ADDRS] = factory.createScalar(sp.mangle_i2c_addrs);
		return retStruct;
	}
};

#endif