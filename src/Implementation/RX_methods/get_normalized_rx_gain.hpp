#ifndef _GET_NORMALIZED_RX_GAIN_HPP_
#define _GET_NORMALIZED_RX_GAIN_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual double 	get_normalized_rx_gain (size_t chan=0)
class GetNormalizedRxGain : public MexObjectRunner<INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        double normalizedGain { };
        if(inputs.size() == 0) {
            normalizedGain = uhd->getUhd()->get_normalized_rx_gain();
        }
        else {
            const size_t chan { inputs[0][0][0] };
            normalizedGain = uhd->getUhd()->get_normalized_rx_gain();
        }
        outputs[0] = factory.createScalar(normalizedGain);
    }
};

#endif