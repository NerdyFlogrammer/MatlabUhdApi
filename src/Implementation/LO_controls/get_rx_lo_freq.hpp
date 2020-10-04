#ifndef _GET_RX_LO_FREQ_HPP_
#define _GET_RX_LO_FREQ_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual double 	get_rx_lo_freq (const std::string &name, size_t chan=0)
class GetRxLoFreq : public MexObjectRunner<STRING_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        const std::string name = inputs[0][0][0];
		double rxLoFreq{};
        if(inputs.size() == 1) {
            rxLoFreq = uhd->getUhd()->get_rx_lo_freq(name);
        }
        else {
			const size_t chan{ inputs[1][0][0] };
            rxLoFreq =uhd->getUhd()->get_rx_lo_freq(name, chan);
        }
		outputs[0] = factory.createScalar(rxLoFreq);
    }
};

#endif