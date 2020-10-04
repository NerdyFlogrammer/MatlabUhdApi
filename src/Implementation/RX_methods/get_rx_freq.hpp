#ifndef _GET_RX_FREQ_HPP_
#define _GET_RX_FREQ_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual double 	get_rx_freq (size_t chan=0)
class GetRxFreq : public MexObjectRunner<INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {    
        double rxFreq{};
        if(inputs.size() == 0) {
            rxFreq = uhd->getUhd()->get_rx_freq();
        }
        else {
			const size_t chan{ inputs[0][0][0] };
            rxFreq = uhd->getUhd()->get_rx_freq(chan);
        } 
        outputs[0] = factory.createScalar(rxFreq);
    }
};

#endif