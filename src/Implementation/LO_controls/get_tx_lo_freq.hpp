#ifndef _GET_TX_LO_FREQ_HPP_
#define _GET_TX_LO_FREQ_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual double 	get_tx_lo_freq (const std::string &name, const size_t chan=0)
class GetTxLoFreq : public MexObjectRunner<STRING_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const std::string name = inputs[0][0][0];
		double txLoFreq{};
        if(inputs.size() == 1) {
            txLoFreq = uhd->getUhd()->get_tx_lo_freq(name);
        }
        else {
			const size_t chan{ inputs[1][0][0] };
            txLoFreq = uhd->getUhd()->get_tx_lo_freq(name, chan);
        }
        outputs[0] = factory.createScalar(txLoFreq); 
    }
};

#endif