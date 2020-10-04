#ifndef _GET_TX_SUBDEV_NAME_HPP_
#define _GET_TX_SUBDEV_NAME_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual std::string 	get_tx_subdev_name (size_t chan=0)
class GetTxSubdevName : public MexObjectRunner<INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		std::string txSubdevName{};
		if (inputs.size() == 0) {
			txSubdevName = uhd->getUhd()->get_tx_subdev_name();
		}
		else {
			const size_t chan{ inputs[0][0][0] };
			txSubdevName = uhd->getUhd()->get_tx_subdev_name(chan);
		}
		outputs[0] = factory.createCharArray(txSubdevName);
    }
};

#endif