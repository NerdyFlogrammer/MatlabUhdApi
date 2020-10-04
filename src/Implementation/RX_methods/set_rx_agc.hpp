#ifndef _SET_RX_AGC_HPP_
#define _SET_RX_AGC_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	set_rx_agc (bool enable, size_t chan=0)
class SetRxAgc : public MexObjectRunner<LOGICAL_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        const bool enable { inputs[0][0][0] };
        if(inputs.size() == 1) {
            uhd->getUhd()->set_rx_agc(enable);
        }
        else {
            const size_t chan { inputs[1][0][0] };
            uhd->getUhd()->set_rx_agc(enable, chan);
        }
    }
};

#endif