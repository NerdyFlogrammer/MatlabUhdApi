#ifndef _FE_CONNECTION_FACTORY_HPP_
#define _FE_CONNECTION_FACTORY_HPP_

#include "struct_factory.hpp"
#include <uhd/usrp/fe_connection.hpp>

namespace {
	constexpr auto SAMPLING_MODE	= "sampling_mode";
	constexpr auto IQ_SWAPPED		= "iq_swapped";
	constexpr auto I_INVERTED		= "i_inverted";
	constexpr auto Q_INVERTED		= "q_inverted";
	constexpr auto IF_FREQ			= "if_freq";
}

template<>
struct StructFactory<uhd::usrp::fe_connection_t> {
	inline static auto createCpp(StructArray const & matlabStructArray) -> uhd::usrp::fe_connection_t {
		auto fields = matlabStructArray.getFieldNames();
		std::unordered_set<std::string> fieldset{ fields.begin(), fields.end() };
		auto sampling = uhd::usrp::fe_connection_t::sampling_t::QUADRATURE;
		sampling = 
			structUtils::TypeConverter<uhd::usrp::fe_connection_t::sampling_t>::value(matlabStructArray, SAMPLING_MODE, fieldset, sampling);
		const auto iqSwapped =
			structUtils::TypeConverter<bool>::value(matlabStructArray, IQ_SWAPPED, fieldset, false);
		const auto iInverted =
			structUtils::TypeConverter<bool>::value(matlabStructArray, I_INVERTED, fieldset, false);
		const auto qInverted =
			structUtils::TypeConverter<bool>::value(matlabStructArray, Q_INVERTED, fieldset, false);
		const auto ifFreq =
			structUtils::TypeConverter<double>::value(matlabStructArray, IF_FREQ, fieldset, 0.0);
		uhd::usrp::fe_connection_t feConn(sampling, iqSwapped, iInverted, qInverted, ifFreq);
		return feConn;
	}

	inline static auto createMatlab(uhd::usrp::fe_connection_t& feConn) -> matlab::data::StructArray {
		matlab::data::ArrayFactory factory{};
		const matlab::data::ArrayDimensions scalar{ 1, 1 };
		auto retStruct =
			factory.createStructArray(
				scalar,
				{ SAMPLING_MODE, IQ_SWAPPED, I_INVERTED, Q_INVERTED, IF_FREQ }
		);
		retStruct[0][SAMPLING_MODE] = factory.createScalar(static_cast<int>(feConn.get_sampling_mode()));
		retStruct[0][IQ_SWAPPED] = factory.createScalar(feConn.is_iq_swapped());
		retStruct[0][I_INVERTED] = factory.createScalar(feConn.is_i_inverted());
		retStruct[0][Q_INVERTED] = factory.createScalar(feConn.is_q_inverted());
		retStruct[0][IF_FREQ] = factory.createScalar(feConn.get_if_freq());
		return retStruct;
	}
};

#endif