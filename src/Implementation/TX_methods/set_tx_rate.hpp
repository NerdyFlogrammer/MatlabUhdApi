#ifndef _SET_TX_RATE_HPP_
#define _SET_TX_RATE_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	set_tx_rate (double rate, size_t chan=ALL_CHANS)
class SetTxRate : public MexObjectRunner<DOUBLE_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const double rate{ inputs[0][0][0] };
        if(inputs.size() == 1) {
            uhd->getUhd()->set_tx_rate(rate);
        }
        else {
			const size_t chan{ inputs[1][0][0] };
            uhd->getUhd()->set_tx_rate(rate, chan);
        }        
    }
};

#endif