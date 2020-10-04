#ifndef _GET_REGISTER_INFO_HPP_
#define _GET_REGISTER_INFO_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Structs/register_info_factory.hpp"

//virtual register_info_t get_register_info(const std::string& path, const size_t mboard = 0)
class GetRegisterInfo : public MexObjectRunner<STRING_REQUIRED, INT64> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const std::string path = inputs[0][0][0];
		uhd::usrp::multi_usrp::register_info_t regInfo{ };
		if (inputs.size() == 1) {
			regInfo = uhd->getUhd()->get_register_info(path);
		}
		else {
			const size_t mboard{ inputs[1][0][0] };
			regInfo = uhd->getUhd()->get_register_info(path, mboard);
		}
		outputs[0] = StructFactory<uhd::usrp::multi_usrp::register_info_t>::createMatlab(regInfo);
	}
};

#endif