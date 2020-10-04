#ifndef _SET_RX_LO_FREQ_HPP_
#define _SET_RX_LO_FREQ_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual double 	set_rx_lo_freq (double freq, const std::string &name, size_t chan=0)
class SetRxLoFreq : public MexObjectRunner<DOUBLE_REQUIRED, STRING_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        const double freq = inputs[0][0][0];
        const std::string name = inputs[1][0][0];
		double retVal{ };
        if(inputs.size() == 2) {
            retVal = uhd->getUhd()->set_rx_lo_freq(freq, name);
        }
        else {
			const size_t chan{ inputs[2][0][0] };
            retVal = uhd->getUhd()->set_rx_lo_freq(freq, name, chan);
        }
		outputs[0] = factory.createScalar(retVal);
    }
};

#endif