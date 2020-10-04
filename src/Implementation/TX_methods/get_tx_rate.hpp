#ifndef _GET_TX_RATE_HPP_
#define _GET_TX_RATE_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual double 	get_tx_rate (size_t chan=0)
class GetTxRate : public MexObjectRunner<INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		double txRate{};
        if(inputs.size() == 0) {
			txRate = uhd->getUhd()->get_tx_rate();
        }
        else {
			const size_t chan{ inputs[0][0][0] };
			txRate = uhd->getUhd()->get_tx_rate(chan);
        }     
		outputs[0] = factory.createScalar(txRate);
    }
};

#endif