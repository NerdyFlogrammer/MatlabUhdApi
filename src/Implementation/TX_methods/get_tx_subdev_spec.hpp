#ifndef _GET_TX_SUBDEV_SPEC_HPP_
#define _GET_TX_SUBDEV_SPEC_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual uhd::usrp::subdev_spec_t uhd::usrp::multi_usrp::get_tx_subdev_spec(size_t mboard = 0) 	
class GetTxSubdevSpec : public MexObjectRunner<INT64> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		if (inputs.size() == 0) {
			auto subdev{ uhd->getUhd()->get_tx_subdev_spec() };
			outputs[0] = factory.createCharArray(subdev.to_string());
		}
		else {
			const size_t mboard{ inputs[0][0][0] };
			auto subdev{ uhd->getUhd()->get_tx_subdev_spec(mboard) };
			outputs[0] = factory.createCharArray(subdev.to_string());
		}
	}
};

#endif