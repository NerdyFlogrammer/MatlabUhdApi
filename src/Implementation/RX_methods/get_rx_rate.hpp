#ifndef _GET_RX_RATE_HPP_
#define _GET_RX_RATE_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual double 	get_rx_rate (size_t chan=0)
class GetRxRate : public MexObjectRunner<INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		double rxRate{};
        if(inputs.size() == 0) {
            rxRate = uhd->getUhd()->get_rx_rate();
        }
        else {
			const size_t chan{ inputs[0][0][0] };
            rxRate = uhd->getUhd()->get_rx_rate(chan);
        }        
		outputs[0] = factory.createScalar(rxRate);
    }
};

#endif