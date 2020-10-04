#ifndef _SPI_CONFIG_FACTORY_HPP_
#define _SPI_CONFIG_FACTORY_HPP_

#include "struct_factory.hpp"
#include <uhd/usrp/dboard_iface.hpp>

namespace {
	constexpr auto MOSI_EDGE = "mosi_edge";
	constexpr auto MISO_EDGE = "miso_edge";
	constexpr auto USE_CUSTOM_DIVIDER = "use_custom_divider";
	constexpr auto DIVIDER = "divider";
}

template<>
struct StructFactory<uhd::spi_config_t> {
	inline static auto createCpp(StructArray const & matlabStructArray) -> uhd::spi_config_t {
		auto fields = matlabStructArray.getFieldNames();
		std::unordered_set<std::string> fieldset{ fields.begin(), fields.end() };
		uhd::spi_config_t sc{ };
		sc.mosi_edge =
			structUtils::TypeConverter<uhd::spi_config_t::edge_t>::value(matlabStructArray, MOSI_EDGE, fieldset, sc.mosi_edge);
		sc.miso_edge =
			structUtils::TypeConverter<uhd::spi_config_t::edge_t>::value(matlabStructArray, MISO_EDGE, fieldset, sc.miso_edge);
		sc.use_custom_divider =
			structUtils::TypeConverter<bool>::value(matlabStructArray, USE_CUSTOM_DIVIDER, fieldset, sc.use_custom_divider);
		sc.divider = 
			structUtils::TypeConverter<int64_t>::value(matlabStructArray, DIVIDER, fieldset, sc.divider);
		return sc;
	}

	inline static auto createMatlab(uhd::spi_config_t sc) -> matlab::data::StructArray {
		matlab::data::ArrayFactory factory{};
		const matlab::data::ArrayDimensions scalar{ 1, 1 };
		auto retStruct =
			factory.createStructArray(
				scalar,
				{ MOSI_EDGE, MISO_EDGE, USE_CUSTOM_DIVIDER, DIVIDER }
		);
		retStruct[0][MOSI_EDGE] = factory.createScalar(static_cast<int32_t>(sc.mosi_edge));
		retStruct[0][MISO_EDGE] = factory.createScalar(static_cast<int32_t>(sc.miso_edge));
		retStruct[0][USE_CUSTOM_DIVIDER] = factory.createScalar(sc.use_custom_divider);
		retStruct[0][DIVIDER] = factory.createScalar(sc.divider);
		return retStruct;
	}
};

#endif