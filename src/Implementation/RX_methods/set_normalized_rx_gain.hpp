#ifndef _SET_NORMALIZED_RX_GAIN_HPP_
#define _SET_NORMALIZED_RX_GAIN_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	set_normalized_rx_gain (double gain, size_t chan=0)
class SetNormalizedRxGain : public MexObjectRunner<DOUBLE_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        const double gain { inputs[0][0][0] };
        if(inputs.size() == 1){
            uhd->getUhd()->set_normalized_rx_gain(gain);
        }
        else {
            const size_t chan { inputs[1][0][0] };
            uhd->getUhd()->set_normalized_rx_gain(gain, chan);
        }
    }
};

#endif