#ifndef _GET_USRP_RX_INFO_HPP_
#define _GET_USRP_RX_INFO_HPP_

#include "../Structs/dict_struct_factory.hpp"
#include "../../API/mex_object_runner.hpp"


using matlab::data::StructArray;

//virtual dict< std::string, std::string > 	get_usrp_rx_info (size_t chan=0)
class GetUsrpRxInfo : public MexObjectRunner<INT64> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		if (inputs.size() == 0) {
			const auto dict = uhd->getUhd()->get_usrp_rx_info();
			outputs[0] = getDictStruct(dict);
		}
		else {
			const size_t chan{ inputs[0][0][0] };
			const auto dict = uhd->getUhd()->get_usrp_rx_info(chan);
			outputs[0] = getDictStruct(dict);
		}
	}
};

#endif