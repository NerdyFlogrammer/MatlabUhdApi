#ifndef _GET_RX_GAIN_HPP_
#define _GET_RX_GAIN_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual double 	get_rx_gain (const std::string &name, size_t chan=0)
class GetRxGain : public MexObjectRunner<STRING_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        const std::string name = inputs[0][0][0];
        double gain {};
        if(inputs.size() == 1) {
            gain = uhd->getUhd()->get_rx_gain(name);
        }
        else {
            const size_t chan { inputs[1][0][0] };
            gain = uhd->getUhd()->get_rx_gain(name, chan);
        }
        outputs[0] = factory.createScalar(gain);
    }
};

#endif