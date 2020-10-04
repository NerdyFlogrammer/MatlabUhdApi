#ifndef _SET_RX_GAIN_HPP_
#define _SET_RX_GAIN_HPP_

#include "../../API/mex_object_runner.hpp"

//set_rx_gain (double gain, const std::string &name, size_t chan=0)
class SetRxGain : public MexObjectRunner<DOUBLE_REQUIRED, STRING_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const double gain{ inputs[0][0][0] };
        const std::string name = inputs[1][0][0];
        if(inputs.size() == 2) {
            uhd->getUhd()->set_rx_gain(gain, name);
        }
        else {
			const size_t chan{ inputs[2][0][0] };
             uhd->getUhd()->set_rx_gain(gain, name, chan);
        }  
    }
};

#endif