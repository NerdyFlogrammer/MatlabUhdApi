#ifndef _SET_RX_RATE_HPP_
#define _SET_RX_RATE_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	set_rx_rate (double rate, size_t chan=ALL_CHANS)
class SetRxRate : public MexObjectRunner<DOUBLE_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        const double rate = inputs[0][0][0];
        if(inputs.size() == 1) {
            uhd->getUhd()->set_rx_rate(rate);
        }
        else {
            const size_t chan = inputs[1][0][0];
            uhd->getUhd()->set_rx_rate(rate, chan);
        }        
    }
};

#endif