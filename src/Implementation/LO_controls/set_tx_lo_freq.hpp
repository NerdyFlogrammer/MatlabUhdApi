#ifndef _SET_TX_LO_FREQ_HPP_
#define _SET_TX_LO_FREQ_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual double 	set_tx_lo_freq (const double freq, const std::string &name, const size_t chan=0)
class SetTxLoFreq : public MexObjectRunner<DOUBLE_REQUIRED, STRING_REQUIRED, INT64>{
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const double freq{ inputs[0][0][0] };
		const std::string name = inputs[1][0][0];
        if(inputs.size() == 2) {
            uhd->getUhd()->set_tx_lo_freq(freq, name);
        }
        else {
			const size_t chan{ inputs[2][0][0] };
            uhd->getUhd()->set_tx_lo_freq(freq, name, chan);
        }
    }
};

#endif