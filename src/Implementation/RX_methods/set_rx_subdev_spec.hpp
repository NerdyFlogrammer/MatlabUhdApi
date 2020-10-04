#ifndef _SET_RX_SUBDEV_SPEC_HPP_
#define _SET_RX_SUBDEV_SPEC_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void uhd::usrp::multi_usrp::set_rx_subdev_spec(const uhd::usrp::subdev_spec_t &  	spec, size_t mboard = ALL_MBOARDS)
class SetRxSubdevSpec : public MexObjectRunner<STRING_REQUIRED, INT64> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const std::string markup = inputs[0][0][0];
		const uhd::usrp::subdev_spec_t subdev{ markup };
		if (inputs.size() == 1) {
			uhd->getUhd()->set_rx_subdev_spec(subdev);
		}
		else {
			const size_t mboard{ inputs[1][0][0] };
			uhd->getUhd()->set_rx_subdev_spec(subdev, mboard);
		}
	}
};

#endif