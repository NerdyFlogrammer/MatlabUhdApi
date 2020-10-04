#ifndef _GET_RX_SUBDEV_NAME_HPP_
#define _GET_RX_SUBDEV_NAME_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual std::string 	get_rx_subdev_name (size_t chan=0)
class GetRxSubdevName : public MexObjectRunner<INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        std::string subdevName{};
        if(inputs.size() == 0) {
            subdevName = uhd->getUhd()->get_rx_subdev_name();
        }
        else {
			const size_t mboard{ inputs[0][0][0] };
            subdevName = uhd->getUhd()->get_rx_subdev_name(mboard);
        }    
        outputs[0] = factory.createCharArray(subdevName);
    }
};

#endif